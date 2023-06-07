#include <unistd.h>
#include <stdio.h>
#include <fstream>
#include <mutex>

#include "engine_server/SpecyEngine.h"
#include "engine_server/Config.h"
#include "engine_server/Init.h"

using namespace std;

// main is the entrypoint of SpecyEngine
int main(int argc, char *argv[])
{

    if (init_logger_config(argc, argv))
    {
        SPDLOG_INFO("Init Logger and monitor faile!");
        return int(EngineStatus::kInitLoggerError);
    }

    SpecyEngine specyEngine;
    // create http client use for query data service
    if (specyEngine.LaunchDataService() != 0)
    {
        SPDLOG_INFO("launch dataservice Failure");
        return -1;
    }

    // then, launch main grpc server to start compliance engine service
    if (specyEngine.LaunchGRPCServer() != 0)
    {
        SPDLOG_INFO("Launch gRPC Server Failure");
        return int(EngineStatus::kGRPCServerError);
    }

    return 0;
}
