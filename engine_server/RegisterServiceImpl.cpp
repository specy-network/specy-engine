
#include <vector>
#include <spdlog/spdlog.h>
#include "RegisterServiceImpl.h"

using namespace std;

#define PUB_KEY_SIZE 64
#define PUB_ENCRYPT_KEY_SIZE 512  //for RSA pem format

string mock_verification_report = "{\"nonce\":\"35E8FB64ACFB4A8E\",\"id\":\"284773557701539118279755254416631834508\",\"timestamp\":\"2018-07-11T19:30:35.556996\",\"epidPseudonym\":\"2iBfFyk5LE9du4skK9JjlRh1x5RvCIz/Z2nnoViIYY8W8TmIHg53UlEm2sp8NYVgT+LGSp0oxZgFcIg4p0BWxXqoBEEDnJFaVxgw0fS/RfhtF8yVNbVQjYjgQjw06wPalXzzNnjFpb873Rycj3JKSzkR3KfvKZfA/CJqEkTZK7U=\",\"isvEnclaveQuoteStatus\":\"GROUP_OUT_OF_DATE\",\"platformInfoBlob\":\"1502006504000700000808010101010000000000000000000007000006000000020000000000000AE791776C1D5C169132CA96D56CC2D59E5A46F23E39933DFB3B4962A8608AB53D84F77D254627D906B46F08073D33FF511E74BC318E8E0C37483C5B08899D1B5E9F\",\"isvEnclaveQuoteBody\":\"AgABAOcKAAAGAAUAAAAAAImTjvVbjrhQGXLFwbdtyMgAAAAAAAAAAAAAAAAAAAAABwf///8BAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABwAAAAAAAAAHAAAAAAAAAMnL+UpC5HcF6MBCXsbYd5KUw2gc1tWgNPHNtK4g1NgKAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACp0uDGT8avpUCoA1LU47KLt5L/RJSpeFFT9807MyvETgAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAOeQAQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAy7+m9Dx2rPbbbBWJUud3AHHnxoFWhlMQCyNjtVRvD2AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\"}";

grpc::Status RegisterServiceImpl::GetEngineInfo(::grpc::ServerContext* context, 
                                            const request_proto::EngineInfoRequest* request, 
                                            request_proto::EngineInfoResponse* response) {
    SPDLOG_INFO("--- GetRegisterInfo start cosmos---");
    uint32_t error_code = StartRemoteAttestationCosmos(response);

    SPDLOG_INFO("--- GetRegisterInfo finish ---");
    return grpc::Status::OK;
}



uint32_t RegisterServiceImpl::StartRemoteAttestationCosmos(request_proto::EngineInfoResponse *const register_resp) {

    uint32_t enclave_ret;

    string attestation_verification_report;

    SPDLOG_INFO("start remote attestation");

    return 0;
}

