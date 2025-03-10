#ifndef _RPC_PROVIDER_
#define _RPC_PROVIDER_
#include "google/protobuf/service.h"
#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/InetAddress.h>
#include <string>
#include <unordered_map>

class RpcProvider
{
public:
    // 将本地服务发布到rpc节点上
    void notifyService(google::protobuf::Service *service);
    // 启动rpc节点
    void run();
private:
    // 服务器的回调函数
    // 连接回调
    void onConnection(const muduo::net::TcpConnectionPtr & conn);
    // 消息回调
    void onMessage(const muduo::net::TcpConnectionPtr & conn, muduo::net::Buffer * buffer, muduo::Timestamp);

private:
    // 定义事件循环
    muduo::net::EventLoop eventLoop_;
    // 定义存储每个服务中包含的方法信息
    struct ServiceInof
    {
        google::protobuf::Service *service_;
        // 该服务对应的方法
        std::unordered_map<std::string, const google::protobuf::MethodDescriptor *> methodMap_;
    };

    // 存放服务的信息
    std::unordered_map<std::string, ServiceInof> serviceMap_;
};

#endif
