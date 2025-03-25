#include "mprpcchannel.h"

// 通过调用该方法, 将参数进行序列化和网络发送
void MprcpChannel::CallMethod(const google::protobuf::MethodDescriptor *method,
                google::protobuf::RpcController *controller,
                const google::protobuf::Message *request,
                google::protobuf::Message *response,
                google::protobuf::Closure *done)
{
   // 得到请求方法对应的服务
   const google::protobuf::ServiceDescriptor *service = method->service();
    // 服务的名字
   std::string server_name = service->name();
   // 方法的名字
   std::string method_name = method->name();
    // 将请求参数序列化, 得到请求参数的大小
   std::string args_str;
   int args_size;
   if (request->SerializeToString(&args_str))
   {
       // 得到参数的大小
       args_size = args_str.size();
   }
    else
    {
        controller->SetFailed("request->SerializeToString(&args_str) err");
        std::cout << "request->SerializeToString(&args_str) err" << std::endl;
        return;
    }
    std::cout << "----------------------------------" << std::endl;
    std::cout << "server_name: " << server_name << std::endl;
    std::cout << "method_name: " << method_name << std::endl;
    std::cout << "args_size: " << args_size << std::endl;
    std::cout << "args_str: " << args_str << std::endl;
    std::cout << "----------------------------------" << std::endl;

    /* 将 server_name method_name args_size  args_str 打包成
    rpcheader_size  rpcheader_str(server_name method_name args_size  args_str)  args_str 
    */
    Header::Rpcheader rpcheader;
    rpcheader.set_server_name(server_name);
    rpcheader.set_method_name(method_name);
    rpcheader.set_args_size(args_size);

    std::string rpcheader_str;
    int rpcheader_size;
    if (rpcheader.SerializeToString(&rpcheader_str))
    {
        rpcheader_size = rpcheader_str.size();
    }
    else
    {
        controller->SetFailed("rpcheader.SerializeToString(&rpcheader_str) err");
        std::cout << "rpcheader.SerializeToString(&rpcheader_str) err" << std::endl;
        return;
    }
    // 将数据进行打包发送
    std::string sendstr;

    sendstr.insert(0, (char *)&rpcheader_size, 4);
    sendstr += rpcheader_str;
    sendstr += args_str;


    // 通过建立tcp连接发送数据
    // 创建连接的套接字
    int cfd = socket(AF_INET, SOCK_STREAM, 0);
    if(cfd == -1)
    {
        std::cout << "socket err" << std::endl;
        controller->SetFailed("socket err");
        return;
    }
    // 连接服务器
    short port = std::stoi(MprpcApplication::instance()->getConfig().getFile("rpcserver_port"));
    std::string ip = MprpcApplication::instance()->getConfig().getFile("rpcserver_ip");
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip.c_str());

    if(-1 == connect(cfd, (struct sockaddr*)&addr, sizeof(addr)))
    {
        std::cout << "connect err" << std::endl;
        controller->SetFailed("connect err");
        return;
    }

    // 把数据发送出去
    int lens = sendstr.size() + 1;
    char *buf = (char*)sendstr.c_str();
    while (lens)
    {
        int len = send(cfd, buf, strlen(buf) + 1, 0);
        if(len > 0)
        {
            lens -= len;
            buf += len;
        }
        else if(len == 0)
        {
            // 服务器断开连接
            close(cfd);
            return;
        }
        else
        {
            controller->SetFailed("send err: ");
            std::cout << "send err: " << sendstr << std::endl;
            close(cfd);
            return;
        }
    }
    // 接受服务器的响应消息
    char buffer[1024] = {0};
    int recvsize = recv(cfd, buffer, sizeof(buffer), 0);
    if (recvsize == -1)
    {
        std::cout << "recv err" << std::endl;
        controller->SetFailed("recv err");
        close(cfd);
        return;
    }

    // 将响应的数据添加到 response中
    /*std::string response_str(std::string(buffer), 0, recvsize);
        出现bug string的构造函数遇到/0就结束了
    */
    if(response->ParseFromArray(buffer, recvsize) == false)
    {
        std::cout << "response->ParseFromString(response_str) err. " << buffer << std::endl;
        controller->SetFailed("response->ParseFromString(response_str) err. ");
        
        close(cfd);
        return;
    }
    close(cfd);
}