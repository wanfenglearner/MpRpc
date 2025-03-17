
#include <iostream>
#include "mprpcapplication.h"
#include "user.pb.h"
#include "mprpcchannel.h"


int main(int argc, char** argv)
{
    // 初始化框架
    MprpcApplication::instance()->init(agrc, aargv);

    // 构造函数传递 channel  channel->CallMethod 通过框架对数据进行序列化和网络发送

    RPC::UserServiceRpc_Stub stub(new MprcpChannel());

    

    return 0;
}
