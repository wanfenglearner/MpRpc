#include <iostream>
#include <string>
#include "user.pb.h"
#include "mprpcapplication.h"
#include "rpcprovider.h"

class UserService : public RPC::UserServiceRpc
{
public:
    // 本地的服务方法
    bool Login(std::string name, std::string pwd)
    {
        std::cout << "本地服务方法: " << std::endl;
        std::cout << "name: " << name << " pwd: " << pwd << std::endl;
        return true;
    }
    /* 重写rpc描述的方法 这个是使用框架
        框架把请求参数LoginRequest传给业务层, 根据传入的参数进行调用本地业务
        在通过LoginResponse写入响应 done调用回调函数发送给调用方
    */
    void Login(::google::protobuf::RpcController* controller,
                       const ::RPC::LoginRequest* request,
                       ::RPC::LoginResponse* response,
                       ::google::protobuf::Closure* done)
    {
        // 得到请求参数
        std::string name = request->name();
        std::string pwd = request->pwd();

        // 执行要调用的本地方法
        bool res = Login(name, pwd);

        // 写入响应参数
        response->set_success(res);
        RPC::ResultCode *code = response->mutable_code();
        code->set_errcode(0);
        code->set_errmsg("");

        // 执行回调函数, 把响应参数序列化通过网络发送出去(框架完成)
        done->Run();
    }
};

int main(int argc, char** argv)
{
    // 初始化Mprpc框架
    MprpcApplication::instance()->init(argc, argv);

    // 将UserService 发布到rpc服务节点上
    RpcProvider provider;
    provider.notifyService(new UserService);

    // 启动rpc服务节点, 阻塞等待rpc调用请求
    provider.run();

    return 0;
}