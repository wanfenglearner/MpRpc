
#include <iostream>
#include "mprpcapplication.h"
#include "logger.h"


int main(int argc, char** argv)
{

    // 初始化框架
    MprpcApplication::instance()->init(argc, argv);

    // 构造函数传递 channel  channel->CallMethod 通过框架对数据进行序列化和网络发送

    RPC::FriendService_Stub stub(new MprcpChannel());

    // 构造请求参数和 得到相应的数据
    RPC::GetFriendRequest request;
    RPC::GetFriendResponse response;
    request.set_id(10000);

    MprpcController controller;

    // Login 底层会调用 channel->CallMethod 进行请求参数的序列化和网络发送
    stub.GetFriend(&controller, &request, &response, nullptr);

    if(controller.Failed() == false)
    {
        int n = response.friends_size();
        std::cout << "rpc调用的响应: " << std::endl;
        for (int i = 0; i < n; ++i)
        {
            std::cout << "name: " << response.friends(i) << std::endl;
        }
    }
    else
    {
        std::cout << "失败信息:" << std::endl;
        std::cout << controller.ErrorText() << std::endl;
    }
    return 0;
}
