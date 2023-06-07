#include <iostream>
#include <map>
#include <memory>

#include <spdlog/spdlog.h>
#include <yaml-cpp/yaml.h>

#include "EngineServer.h"

enum class EngineStatus
{
    kOK = 0,
    kEnclaveLoadError,
    kLocalAttestationError,
    kDataserviceError,
    kGRPCServerError,
    kConfigReadError,
    kInitLoggerError,
};

// #define KEY_MANAGEMENT_ENCLAVE_FILENAME "key_management_enclave.signed.so"
// #define RULE_ENCLAVE_FILENAME "rule_enclave.signed.so"
// #define BINDING_ENCLAVE_FILENAME "binding_enclave.signed.so"

// map from enclave id to enclave index (used for ocall forward)
// extern std::map<sgx_enclave_id_t, SubModule> g_enclave_id_map;
// extern std::unique_ptr<HttpClient> httpClient;

class SpecyEngine
{
    public:
        // grpc server
        uint32_t LaunchGRPCServer();

        // Data service for 
        uint32_t LaunchDataService();


    private:
        EngineServer server;
        
};