#include "mprpcconfig.h"
#include <fstream>

void delSpace(std::string& s)
{
    int k = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if(s[i] == ' ')
        {
            continue;
        }
        s[k++] = s[i];
    }
    s = s.substr(0, k);
}

// 读取配置文件信息
void MprpcConfig::loadFile(const char *file)
{
    // 打开文件
    std::ifstream ifs(file);
    if(ifs.is_open())
    {
        std::string s;
        while(getline(ifs, s))
        {
            // 去掉配置文件中多余的空格
            delSpace(s);
            // 判断是不是注释
            int index = s.find('#');
            if(index != -1)
            {
                continue;
            }
            // 读取信息
            index = s.find('=');
            if(index == -1)
            {
                continue;
            }
            std::string key = s.substr(0, index);
            std::string value = s.substr(index + 1);
            configfileMap_.insert({key, value});
        }

        ifs.close();
    }
    else
    {
        std::cout << "文件打开失败" << std::endl;
        exit(-1);
    }
}
// 返回指定下标的信息
std::string MprpcConfig::getFile(const std::string key)
{
    auto it = configfileMap_.find(key);
    if(it == configfileMap_.end())
    {
        return "";
    }
    return it->second;
}