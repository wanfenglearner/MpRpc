
#ifndef _MPRPC_CONTROLLER_H_
#define _MPRPC_CONTROLLER_H_
#include <google/protobuf/service.h>

class MprpcController : public google::protobuf::RpcController
{
public:
    // 构造函数
    MprpcController();
    // 重置状态信息
    void Reset();
    // 判断是否失败
    bool Failed() const;
    // 返回错误信息
    std::string ErrorText() const;
    // 设置失败信息
    void SetFailed(const std::string &reason);

    // 暂无重写
    void StartCancel();

    bool IsCanceled() const;

    void NotifyOnCancel(google::protobuf::Closure* callback);

private:
    bool failed_;
    std::string errText_;
};





#endif
