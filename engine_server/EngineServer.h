#pragma once
#include "ErrorType.h"
#include <grpcpp/grpcpp.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/health_check_service_interface.h>

class EngineServer
{
public:
    uint32_t RunServer();

    uint32_t ReadConfig();

private:
    std::unique_ptr<grpc::Server> server;
    std::string address;
};