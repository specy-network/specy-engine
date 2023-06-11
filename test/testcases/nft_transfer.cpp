#include "nft_transfer.h"
#include <string>
#include <regex>

using namespace json11;
using namespace std;
// data of binding
string TestTaskHash_0elements = "0x1000";
string TestTaskHash_4elements = "0x1004";

string TestTaskRule_0elements = "regulation nft_reward entities { entity interchainnft {hash  sender  receiver  class_id  tocken_id  timestamp }  entity reward_list0 { token_id } } rules { rule nft_white_list { count on interchainnft where interchainnft.token_id in reward_list0 after 2023-01-01T00:00:00+08:00 within 1 days } }";
string TestTaskRule_4elements = R"(regulation nft_reward entities { entity interchainnft {hash  sender  receiver  class_id  tocken_id  timestamp }  entity reward_list4 { token_id } } rules { rule nft_white_list { count on interchainnft where interchainnft.token_id in reward_list4 after 2023-01-01T00:00:00+08:00 within 1 days } })";

string TestTaskRewardList_0elements = "";
string TestTaskRewardList_4elements = "";


void mockTaskRequest_NFTList_0elements(request_proto::TaskRequest* request) {
    request->set_taskhash(TestTaskHash_0elements);
}

void mockTaskRequest_NFTList_4elements(request_proto::TaskRequest* request) {
    request->set_taskhash(TestTaskHash_4elements);
}

void InitMockDataBase_NFT_0elements(MockDatabase_NFT& mockDatabase) {
    mockDatabase.insertTask("0x307831303030", TestTaskRule_0elements);
}

void InitMockDataBase_NFT_4elements(MockDatabase_NFT& mockDatabase) {
    mockDatabase.insertTask("0x307831303034", TestTaskRule_4elements);
}

std::string MockDatabase_NFTlist::handleQuery(std::string& query, std::string& target){
    cout << target << endl;
    cout << query << endl;
    if (target.compare("ics721") == 0) 
        return handleICS721Query(query);

    if (target.compare("rewards") == 0)
        return handleRewardListQuery(query);
    
    if (target.compare("specy") == 0)
        return MockDatabase_NFT::handleSystemQuery(query);

    return "";
}

bool MockDatabase_NFTlist::matchDatabase (std::string& target) {
    if (target.compare("ics721") == 0)
        return true;
    if (target.compare("rewards") == 0)
        return true;
    if (target.compare("specy") == 0)
        return true;
    return false;
}


std::string MockDatabase_NFTlist::handleRewardListQuery(std::string& query) {
    Json::array lists;
    lists.push_back("succ");

    Json::object list {
        {"list", lists},
    };

    Json::object data {
        {"data", Json::object{list}}
    };
    Json result = data;
    return result.dump();
}

std::string MockDatabase_NFTlist::handleICS721Query(std::string& query) {
    Json::object value1 {
        {"receiver", "cosmos17teac5cla5j886k4pyr4xhyz252llnr09x4gdu"},
        {"class_id", "succ"},
    };
    Json::object value2 {
        {"receiver", "cosmos17teac5cla5j886k4pyr4xhyz252llnr09x4gdi"},
        {"class_id", "succ"},
    };
    Json::object value3 {
        {"receiver", "cosmos17teac5cla5j886k4pyr4xhyz252llnr09x4gduo"},
        {"class_id", "succ"},
    };
    Json::object value4 {
        {"receiver", "cosmos17teac5cla5j886k4pyr4xhyz252llnr09x4gduy"},
        {"class_id", "succ"},
    };
    Json::array ics721list;
    ics721list.push_back(value1);
    ics721list.push_back(value2);
    ics721list.push_back(value3);
    ics721list.push_back(value4);

    Json::object transfers {
       { "interchainnftreceives", ics721list}
    };
    Json::object data {
        {"data", Json::object{transfers}}
    };
    cout << "end" <<endl;
    Json result = data;
    return result.dump();
}