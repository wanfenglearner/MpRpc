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
    void push(const T &msg)
    {
        // 加锁
        std::unique_lock<std::mutex> lock(queMutex_);
        que_.push(msg);
    }
    // 取消息
    T pop()
    {
        std::unique_lock<std::mutex> lock(queMutex_);
        cond_.wait(lock, [=]() -> bool{
            return !que_.empty(); 
        });
        T data = que_.front();
        que_.pop();
        return data;
    }

private:
    std::queue<T> que_;
    std::mutex queMutex_;
    std::condition_variable cond_;
};

#endif 