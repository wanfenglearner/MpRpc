
#ifndef _MPRCP_CHANNEL_
#define _MPRCP_CHANNEL_
#include "google/protobuf/service.h"

#include <google/protobuf/descriptor.h>
#include <google/protobuf/service.h>
#include <google/protobuf/message.h>
#include <google/protobuf/stubs/callback.h>


class MprcpChannel : public google::protobuf::RpcChannel
{
public:
    // 通过调用该方法, 将参数进行序列化和网络发送
    void CallMethod(const google::protobuf::MethodDescriptor *method,
                    google::protobuf::RpcController *controller,
                    const google::protobuf::Message *request,
                    google::protobuf::Message *response,
                    google::protobuf::Closure *done);

private:
};

#endif

