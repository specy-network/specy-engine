#pragma once

#include <iostream>
#include <grpcpp/grpcpp.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>

#include "ErrorType.h"

#include "protos/untrusted/Regulator.grpc.pb.h"
#include "protos/untrusted/Regulator.pb.h"

class  RegulatorServiceImpl final : public request_proto::Regulator::Service
{

    private:
    virtual grpc::Status GetTaskResult(::grpc::ServerContext *context,
                                            grpc::ServerReaderWriter<::request_proto::TaskResponse, ::request_proto::TaskRequest> *stream) override;

    uint32_t ProofRequestProcess(const request_proto::TaskRequest& request, request_proto::TaskResponse* response);
    
};