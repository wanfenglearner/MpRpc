#ifndef __LOGGER_H__
#define __LOGGER_H__

#include "lockqueue.h"


// 定义宏 LOG_INFO("xxx %d %s", 20, "xxxx")
#define LOG_INFO(logmsgformat, ...) \
    do \
    {  \
        Logger *logger = Logger::instance(); \
        logger->setLevel(Level_Info); \
        char c[1024] = {0}; \
        snprintf(c, 1024, logmsgformat, ##__VA_ARGS__); \
        logger->Log(c); \
    } while(0) \

#define LOG_ERR(logmsgformat, ...) \
    do \
    {  \
        Logger *logger = Logger::instance(); \
        logger->setLevel(Level_Error; \
        char c[1024] = {0}; \
        snprintf(c, 1024, logmsgformat, ##__VA_ARGS__); \
        logger->Log(c); \
    } while(0) \

// 表示消息的类型
enum LogLevel
{
    Level_Error,
    Level_Info
};

class Logger
{

public:
    // 获得单例
    static Logger *instance();
    // 设置日志级别
    void setLevel(LogLevel level);
    // 添加日志
    void Log(std::string msg);

private:
    // 记录所记录日志的级别
    int logLevel_;
    LockQueue<std::string> lockque_;
private:
    // 构造函数
    Logger();
    Logger(const Logger &) = delete;
    Logger( Logger &&) = delete;
};

#endif

