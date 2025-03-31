
#ifndef _MPRPC_APPLICATION_
#define _MPRPC_APPLICATION_

#include "mprpcconfig.h"
#include "mprpcapplication.h"
#include "mprpccontroller.h"
#include "friend.pb.h"
#include "mprpcchannel.h"

// Mprpc框架的类
// 实现一个单例模式
class MprpcApplication
{
public:
    // 得到MprpcApplication实例对象
    static MprpcApplication *instance();
    // 初始化框架
    void init(int argc, char **argv);
    // 得到配置信息
    MprpcConfig &getConfig();
private:
    // 配置信息
    MprpcConfig conf_;

private:
    MprpcApplication() = default;
    MprpcApplication(const MprpcApplication &) = delete;
    MprpcApplication(MprpcApplication &&) = delete;
    MprpcApplication& operator=(const MprpcApplication &) = delete;
    MprpcApplication& operator=(MprpcApplication &&) = delete;
};

#endif
