#include "mprpccontroller.h"

// 构造函数
MprpcController::MprpcController()
{
    failed_ = false;
    errText_ = "";
}
// 重置状态信息
void MprpcController::Reset()
{
    failed_ = false;
    errText_ = "";
}
// 判断是否失败
bool MprpcController::Failed() const
{
    return failed_;
}
// 返回错误信息
std::string MprpcController::ErrorText() const
{
    return errText_;
}
// 设置失败信息
void MprpcController::SetFailed(const std::string &reason)
{
    errText_ = reason;
}

// 暂无重写
void MprpcController::StartCancel()
{

}

bool MprpcController::IsCanceled() const
{

}

void MprpcController::NotifyOnCancel(google::protobuf::Closure* callback)
{

}