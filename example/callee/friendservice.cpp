#include <iostream>
#include <string>
#include <vector>
#include "friend.pb.h"
#include "mprpcapplication.h"
#include "mprpcchannel.h"
#include "rpcprovider.h"
#include "logger.h"

class FriendService : public RPC::FriendService
{
public:
    std::vector<std::string> GetFriend(int id)
    {
        std::cout << "本地服务: " << "id: " << id << std::endl;
        std::vector<std::string> vec;
        vec.push_back("zhang san");
        vec.push_back("li si");
        vec.push_back("wang wu");

        return vec;
    }
    void GetFriend(::google::protobuf::RpcController* controller,
                       const ::RPC::GetFriendRequest* request,
                       ::RPC::GetFriendResponse* response,
                       ::google::protobuf::Closure* done)
    {
        // 得到请求
        int id = request->id();

        std::vector<std::string> vec = GetFriend(id);
        // 写入响应参数
        for (int i = 0; i < vec.size(); ++i)
        {
            response->add_friends(vec[i]);
        }
        // 执行回调函数发送响应
        done->Run();
    }
};

int main(int argc, char** argv)
{
    // 测试日志的使用
    LOG_INFO("测试日志");
    // 加载配置文件
    MprpcApplication::instance()->init(argc, argv);

    // 将服务添加到节点上
    RpcProvider provider;
    provider.notifyService(new FriendService());

    // 启动rpc服务节点
    provider.run();

    return 0;
}