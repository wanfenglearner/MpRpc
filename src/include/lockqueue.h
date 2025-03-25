#ifndef __LOCKQUEUE_H__
#define __LOCKQUEUE_H__

#include <queue>
#include <condition_variable>
#include <mutex>
#include <string>

template<typename T>
class LockQueue
{
public:
    //添加消息
    void push(const T &msg);
    // 取消息
    T get();

private:
    std::queue<T> que_;
    std::mutex queMutex_;
    std::condition_variable cond_;
};

#endif 