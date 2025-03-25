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

    bool Register(int id, std::string name, std::string pwd)
    {
        std::cout << "本地服务方法: " << std::endl;
        std::cout << "id: " << id << " name: " << name << " pwd: " << pwd << std::endl;
        return true;
    }
        /* 重写rpc描述的方法 这个是使用框架
            框架把请求参数LoginRequest传给业务层, 根据传入的参数进行调用本地业务
            在通过LoginResponse写入响应 done调用回调函数发送给调用方
        */
        void Login(::google::protobuf::RpcController *controller,
                   const ::RPC::LoginRequest *request,
                   ::RPC::LoginResponse *response,
                   ::google::protobuf::Closure *done)
    {
        // 得到请求参数
        std::string name = request->name();
        std::string pwd = request->pwd();

        // 执行要调用的本地方法
        bool res = Login(name, pwd);

        if (res)
        {
            // 写入响应参数
            response->set_success(res);
            RPC::ResultCode *code = response->mutable_code();
            code->set_errcode(0);
            code->set_errmsg("");
        }
        else
        {
            // 写入响应参数
            response->set_success(res);
            RPC::ResultCode *code = response->mutable_code();
            code->set_errcode(-1);
            code->set_errmsg("call err");

        }

        // 执行回调函数, 把响应参数序列化通过网络发送出去(框架完成)
        done->Run();
    }

    void Register(::google::protobuf::RpcController* controller,
                       const ::RPC::RegisterRequest* request,
                       ::RPC::RegisterResponse* response,
                       ::google::protobuf::Closure* done)
    {
        int id = request->id();
        std::string name = request->name();
        std::string pwd = request->pwd();
        // 调用本地方法
        bool res = Register(id, name, pwd);
        // 将参数写进响应
        if(res)
        {
            response->set_success(res);
            response->mutable_rescode()->set_errcode(0);
            response->mutable_rescode()->set_errmsg("");
        }
        else
        {
            response->set_success(res);
            response->mutable_rescode()->set_errcode(-1);
            response->mutable_rescode()->set_errmsg("Call Request Error");
        }
        // 执行回调
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