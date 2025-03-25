
#ifndef _MPRCP_CHANNEL_
#define _MPRCP_CHANNEL_
#include "google/protobuf/service.h"

#include <google/protobuf/descriptor.h>
#include <google/protobuf/service.h>
#include <google/protobuf/message.h>
#include <google/protobuf/stubs/callback.h>
#include "rpcheader.pb.h"
#include <arpa/inet.h>
#include <unistd.h>
#include "mprpcapplication.h"
#include "mprpccontroller.h"

class MprcpChannel : public google::protobuf::RpcChannel
{
public:
    void CallMethod(
        const google::protobuf::MethodDescriptor *method,
        google::protobuf::RpcController *controller, 
        const google::protobuf::Message *request,
        google::protobuf::Message *response, 
        google::protobuf::Closure *done);
};

#endif

