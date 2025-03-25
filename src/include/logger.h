#ifndef __LOGGER_H__
#define __LOGGER_H__

#include "lockqueue.h"

// 表示消息的类型
enum LogLevel
{
    Level_Error,
    Level_Info
};

class Logger
{

public:
    // 设置日志级别
    void setLevel(LogLevel level);
    // 添加日志
    void Log(std::string msg);

private:
    // 记录所记录日志的级别
    int logLevel_;
    LockQueue<std::string> lockque_;
};

#endif 