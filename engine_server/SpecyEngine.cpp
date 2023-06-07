// LICENSE: Apache 2.0
// https://github.com/RegTech-OXH/compliance-engine
//
// Author:
//
// This file implements methods for ComplianceEngine launching up.

#include "SpecyEngine.h"
#include "dataservice/Dataservice.h"
#include <string>

// #include "KeyManagementEnclave_u.h"
// #include "RuleEnclave_u.h"

using namespace std;

// LaunchGRPCServer is used to launch GRPC server for receiving registration and compliance requests.
uint32_t SpecyEngine::LaunchGRPCServer()
{

    // start grpc server
    // RegulatorServer server;
    if (REQUESTPROCESSOR_ERROR_CODE::kRPSUCCESS != server.RunServer())
    {
        return uint32_t(EngineStatus::kGRPCServerError);
    }

    return uint32_t(EngineStatus::kOK);
}

uint32_t SpecyEngine::LaunchDataService() {
    SPDLOG_INFO("Create http client");
    dataservice.reset(new Dataservice());
    return uint32_t(EngineStatus::kOK);
}
