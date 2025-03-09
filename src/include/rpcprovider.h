#ifndef _RPC_PROVIDER_
#define _RPC_PROVIDER_
#include "google/protobuf/service.h"


class RpcProvider
{
public:
    // 将本地服务发布到rpc节点上
    void notifyService(google::protobuf::Service *service);
    // 启动rpc节点
    void run();

private:


};

#endif
