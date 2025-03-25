#include "rpcprovider.h"
#include "mprpcapplication.h"
#include <google/protobuf/descriptor.h>
#include <google/protobuf/stubs/callback.h>
#include "rpcheader.pb.h"
#include <functional>
#include <thread>
#include <arpa/inet.h>


// 将本地服务发布到rpc节点上
void RpcProvider::notifyService(google::protobuf::Service *service)
{
    // 记录服务和对应的方法信息
    ServiceInof serviceinfo;
    // 获得该服务对象的描述信息
    const google::protobuf::ServiceDescriptor *pserviceDesc = service->GetDescriptor();

    //该服务的名字
    const std::string service_name = pserviceDesc->name();
    std::cout << "service_name: " << service_name << std::endl;
    // 该服务的方法数量
    int methodCnt = pserviceDesc->method_count();

    
    for (int i = 0; i < methodCnt; ++i)
    {
        // 得到每个方法的具体信息
        const google::protobuf::MethodDescriptor* pmethodDesc =  pserviceDesc->method(i);
        std::string method_name = pmethodDesc->name();
        std::cout << "method_name: " << method_name << std::endl;
        serviceinfo.methodMap_.insert({method_name, pmethodDesc});
    }
    // 记录本条方法
    serviceinfo.service_ = service;

    serviceMap_.insert({service_name, serviceinfo});

}
// 启动rpc节点
void RpcProvider::run()
{
    // 定义服务器的ip 端口号
    std::string ip = MprpcApplication::instance()->getConfig().getFile("rpcserver_ip");
    int port = std::stoi(MprpcApplication::instance()->getConfig().getFile("rpcserver_port"));

    //muduo::net::InetAddress addr(ip, port);
     struct sockaddr_in addrs;
    addrs.sin_family = AF_INET;
    addrs.sin_port = htons(port);
    addrs.sin_addr.s_addr = inet_addr(ip.c_str());

    muduo::net::InetAddress addr((const sockaddr_in)addrs);
    // 创建服务器
    muduo::net::TcpServer server(&eventLoop_, addr, "Rpcprovider");

    // 设置回调函数
    server.setConnectionCallback(std::bind(&RpcProvider::onConnection, this, std::placeholders::_1 ));
    server.setMessageCallback(std::bind(&RpcProvider::onMessage, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

    // 设置muduo网络库的线程数量
    server.setThreadNum(std::thread::hardware_concurrency());

    std::cout << "rpc节点服务器启动" << "rpcserver_ip: " << ip << " rpcserver_port: " << port << std::endl;
    // 启动服务器
    server.start();

    // 启动时间循环
    eventLoop_.loop();
}


// 连接回调
void RpcProvider::onConnection(const muduo::net::TcpConnectionPtr & conn)
{
    // 处理客户端连接信息
    if(!conn->connected())
    {

        std::cout << "-------------------------" << std::endl;
        std::cout << "关闭连接" << std::endl;
        std::cout << "-------------------------" << std::endl;
        // 关闭描述符
        conn->shutdown();
    }
    else
    {
        std::cout << "-------------------------" << std::endl;
        std::cout << "建立连接" << std::endl;
        std::cout << "-------------------------" << std::endl;
    }
}
// 消息回调
/* 规定rpcconsumer 发过来的序列化消息格式
    消息头大小(4字节)   消息信息    请求参数
    rpcheader_size  rpcheader_str  args_str
*/
void RpcProvider::onMessage(const muduo::net::TcpConnectionPtr & conn, muduo::net::Buffer* buffer,muduo::Timestamp)
{
    std::string buff = buffer->retrieveAllAsString();
    std::cout << "收到的消息: " << buff << std::endl;
    // 先读消息头大小
    int rpcheader_size;
    buff.copy((char *)&rpcheader_size, 4, 0);
    // 读出消息信息
    std::string rpcheader_str = buff.substr(4, rpcheader_size);

    // 反序列化
    Header::Rpcheader header_str;

    std::string server_name;
    std::string method_name;
    int args_size;

    if(header_str.ParseFromString(rpcheader_str))
    {
        server_name = header_str.server_name();
        method_name = header_str.method_name();
        args_size = header_str.args_size();
    }
    else
    {
        std::cerr << "反序列化失败" << std::endl;
        return;
    }
    
    // 取出请求的参数
    std::string args_str = buff.substr(4 + rpcheader_size, args_size);

   std::cout << "----------------------------------" << std::endl;
    std::cout << "server_name: " << server_name << std::endl;
    std::cout << "method_name: " << method_name << std::endl;
    std::cout << "args_size: " << args_size << std::endl;
    std::cout << "args_str: " << args_str << std::endl;
    std::cout << "----------------------------------" << std::endl;
    
    // 找到对应的服务和方法
    auto sit = serviceMap_.find(server_name);
    if(sit == serviceMap_.end())
    {
        std::cerr << "server_name not find" << std::endl;
        return;
    }
    // 该服务对应的方法
    auto mit = sit->second.methodMap_.find(method_name);
    if(mit == sit->second.methodMap_.end())
    {
        std::cerr << "method_name not find" << std::endl;
        return;
    }
    // 得到服务对象
    google::protobuf::Service *service = sit->second.service_;
    // 得到服务的描述
     const google::protobuf::MethodDescriptor *method = mit->second;

    // 生成rpc request 和response 信息
     google::protobuf::Message *request = service->GetRequestPrototype(method).New();
    if(!request->ParseFromString(args_str))
    {
        std::cout << "request->ParseFromString(args_str) err" << std::endl;
        return;
    }
     google::protobuf::Message *response = service->GetResponsePrototype(method).New();

    // 执行回调函数
    google::protobuf::Closure* done = google::protobuf::NewCallback
    <RpcProvider, const muduo::net::TcpConnectionPtr&, 
      google::protobuf::Message *>

     (this, &RpcProvider::sendRpcResponse, conn, response);
    // 调用本地服务

    service->CallMethod(method, nullptr, request, response, done);
}

// 调用回调 处理response的参数序列化以及网络发送
void RpcProvider::sendRpcResponse(const muduo::net::TcpConnectionPtr& conn,  google::protobuf::Message * response)
{
    // 将响应序列化然后通过网络发送出去
    std::string response_str;
    if(response->SerializeToString(&response_str))
    {
        conn->send(response_str);
    }
    else
    {
        std::cerr << "response->SerializeToString err" << std::endl;
    }
    // 主动关闭连接
    conn->shutdown();
}
