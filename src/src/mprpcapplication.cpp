#include "mprpcapplication.h"
#include <iostream>
#include <unistd.h>
#include <string>

void showArgs()
{
    std::cout << "格式: command -i <config_file>" << std::endl;
}
// 得到MprpcApplication实例对象
MprpcApplication* MprpcApplication::instance()
{
    static MprpcApplication mprpc;
    return &mprpc;
}
// 初始化框架
void MprpcApplication::init(int argc, char **argv)
{
    if(argc < 2)
    {
        showArgs();
        exit(-1);
    }

    // 读取命令行参数
    int c = 0;
    // 配置文件所在目录
    std::string config_file;
    while ((c = getopt(argc, argv, "i:")) != -1)
    {
        switch (c)
        {
        case 'i':
            config_file = optarg;
            break;
        case '?':
            exit(-1);
        default:
            break;
        }
    }
    /* 读取配置文件 rpcserver_ip rpcserver_port zookeeper_ip  
        zookeeper_port
    */
    conf_.loadFile(config_file.c_str());
    std::cout << "rpcserver_ip: " << conf_.getFile("rpcserver_ip") << std::endl;
    std::cout << "rpcserver_port: " << conf_.getFile("rpcserver_port") << std::endl;
    std::cout << "zookeeper_ip: " << conf_.getFile("zookeeper_ip") << std::endl;
    std::cout << "zookeeper_port: "<< conf_.getFile("zookeeper_port") << std::endl;

}
