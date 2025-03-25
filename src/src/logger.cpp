#include "logger.h"
#include <thread>
#include <fstream>
#include <iostream>
#include <cstring>

// 获得单例
Logger *Logger::instance()
{
    static Logger log;
    return &log;
}
// 构造函数
Logger::Logger():
logLevel_(0)
{
    // 开启一个线程专门用来写日志
    std::thread t([&]()
    {
        while(1)
        {
            // 创建一个文件进行写入
            // 以时间进行命名
            time_t tt = time(nullptr);
            struct tm *ptm = localtime(&tt);
            char buf[64] = {0};
            sprintf(buf, "%04d-%02d-%02d.txt", ptm->tm_year + 1900, ptm->tm_mon + 1, ptm->tm_mday);

            std::ofstream ofs(buf, std::ios::app);
            if(ofs.is_open())
            {
                // 将内容写入文件中
                std::string s = lockque_.pop();
                // 产生写入的时间
                memset(buf, 0, sizeof(buf));
                sprintf(buf, "%02d:%02d:%02d-> ", ptm->tm_hour, ptm->tm_min, ptm->tm_sec);
                s.insert(0, buf);
                ofs << s << std::endl;

                ofs.close();
            }
            else
            {
                std::cout << "打开文件失败" << std::endl;
            }
        }
     });


    t.detach();
}

// 设置日志级别
void Logger::setLevel(LogLevel level)
{
    logLevel_ = level;
}
// 添加日志
void Logger::Log(std::string msg)
{
    lockque_.push(msg);
}