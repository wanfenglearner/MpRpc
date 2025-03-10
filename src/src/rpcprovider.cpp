#include "rpcprovider.h"
#include "mprpcapplication.h"
#include <google/protobuf/descriptor.h>
#include <functional>
#include <thread>

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
    muduo::net::InetAddress addr(ip, port);

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

}
// 消息回调
void RpcProvider::onMessage(const muduo::net::TcpConnectionPtr & conn, muduo::net::Buffer* buffer,muduo::Timestamp)
{

}