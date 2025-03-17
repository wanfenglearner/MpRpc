#include "mprpcchannel.h"

// 通过调用该方法, 将参数进行序列化和网络发送
void MprcpChannel::CallMethod(const google::protobuf::MethodDescriptor *method,
                google::protobuf::RpcController *controller,
                const google::protobuf::Message *request,
                google::protobuf::Message *response,
                google::protobuf::Closure *done)
{
    
}