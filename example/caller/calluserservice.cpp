
#include <iostream>
#include "mprpcapplication.h"
#include "user.pb.h"
#include "mprpcchannel.h"


int main(int argc, char** argv)
{
    // 初始化框架
    MprpcApplication::instance()->init(argc, argv);

    // 构造函数传递 channel  channel->CallMethod 通过框架对数据进行序列化和网络发送

    RPC::UserServiceRpc_Stub stub(new MprcpChannel());

    // 构造请求参数和 得到相应的数据
    RPC::LoginRequest request;
    RPC::LoginResponse response;
    request.set_name("zhang san");
    request.set_pwd("123");

    // Login 底层会调用 channel->CallMethod 进行请求参数的序列化和网络发送
    stub.Login(nullptr, &request, &response, nullptr);

    // 得到相应的数据
    if(response.success())
    {
        //成功
        std::cout << "成功: ";
        std::cout << "response.code().errmsg: " << response.code().errmsg();
        std::cout << " success: " << response.success() << std::endl;
    }
    else
    {
         //失败
        std::cout << "失败: ";
        std::cout << "response.code().errmsg: " << response.code().errmsg() << std::endl;
    }


    RPC::RegisterRequest request_reg;
    request_reg.set_id(1000);
    request_reg.set_name("张三");
    request_reg.set_pwd("11111");
    RPC::RegisterResponse response_reg;
    stub.Register(nullptr, &request_reg, &response_reg, nullptr);

     std::cout << "success: " << response_reg.success() << " response_reg.rescode().errmsg(): " <<  response_reg.rescode().errmsg() << std::endl;
    

    return 0;
}
