#ifndef _MPRPC_CONFIG_
#define _MPRPC_CONFIG_

#include <unordered_map>
#include <string>
#include <iostream>

class MprpcConfig
{
public:
    // 读取配置文件信息
    void loadFile(const char *file);
    // 返回指定下标的信息
    std::string getFile(const std::string key);

private:
    // 存放读取到的配置信息
    std::unordered_map<std::string, std::string> configfileMap_;
};

#endif
