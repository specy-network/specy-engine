// LICENSE: Apache 2.0
// https://github.com/RegTech-OXH/compliance-engine
//
// Author:
//
// This file implements RuleProcessor class.

#include "RuleProcessor.h"


#include <regex>
#include <vector>
#include <set>
#include "merklecpp.h"
#include "sgx_tcrypto.h"
// #include "openssl/sha.h"

using namespace std;
using namespace json11;
using namespace antlr4;

static void dumpEntityList(vector<Entity>& entity_list) {
    ocall_print_string("EvaluateRule: dump entity list", __FILE__, __LINE__);

    for (auto &entity : entity_list)
    {
        string entity_string;
        // basic entity info
        auto entity_name = entity.get_name();
        auto attribute_set = entity.get_attribute_set();

        entity_string += ("EvaluateRule: entity: " + entity_name + "[");

        // traverse through attribute set
        uint64_t counter = 0;
        for (auto &attribute : attribute_set)
        {
            if (counter++ > 0)
            {
                entity_string += ", ";
            }
            entity_string += attribute;
        }

        entity_string += "]";

        ocall_print_string((string("EvaluateRule: new entity: ") + entity_string).c_str(), __FILE__, __LINE__);
    }
}

static void dumpEntitySetList(vector<EntitySet>& entity_set_list) {
    ocall_print_string("EvaluateRule: dump entity set list", __FILE__, __LINE__);
    for (auto &entity_set : entity_set_list)
    {
        string entity_set_string;

        // basic entity set info
        auto entity_name = entity_set.get_name();
        auto constraint_list = entity_set.get_constraint_list();

        entity_set_string += ("EvaluateRule: entity set: " + entity_name + "[");

        ocall_print_string(("EvaluateRule: constraint_list size: " +
                            to_string(constraint_list.size())).c_str(), __FILE__, __LINE__);

        // traverse through constraint list
        uint64_t counter = 0;
        for (auto constraint_iter = constraint_list.begin();
             constraint_iter != constraint_list.end(); constraint_iter++)
        {
            if (counter++ > 0)
            {
                entity_set_string += ", ";
            }
            entity_set_string += constraint_iter->Utf8DebugString();
        }

        entity_set_string += "]";

        ocall_print_string((string("EvaluateRule: new entity set: ") + entity_set_string).c_str(), __FILE__, __LINE__);
    }
}

static inline void sha256_sgx(
    const merkle::HashT<32>& l,
    const merkle::HashT<32>& r,
    merkle::HashT<32>& out)
{
    uint8_t block[32 * 2];
    memcpy(&block[0], l.bytes, 32);
    memcpy(&block[32], r.bytes, 32);
    sgx_sha256_msg(block, sizeof(block), &out.bytes);
}

void GenerateQuerySentences (const string& rule_text, vector<string>& sentences) {
    sentences.push_back(R"-({"query" : "{interchainnftreceives(where : {timestamp_gt:1672502400}) { receiver class_id }}"})-");
    sentences.push_back(R"-({"query" : "{rewardlists { list }}"})-");
}

// EvaluateRule is used to regulate transaction with rules
RuleEnclaveStatus RuleProcessor::EvaluateRule(RequestContext *const request_context)
{
    ocall_print_string("enter EvaluateRule", __FILE__, __LINE__);

    RuleEnclaveStatus status_code = RuleEnclaveStatus::kOK;
    const string& rule_text = request_context->get_rule_text();
    vector<string> sentences;

    // generate query sentence
    GenerateQuerySentences(rule_text, sentences);

    // get query result
    DataProvider provider;
    Json query_nft_result;
    provider.QueryDataFromGraphnodeJson(sentences[0], "ics721", query_nft_result);
    ocall_print_string(("entity binding" + query_nft_result.dump()).c_str(), __FILE__, __LINE__);

    Json query_list_result;
    provider.QueryDataFromGraphnodeJson(sentences[1], "rewards", query_list_result);
    ocall_print_string(("entity binding" + query_list_result.dump()).c_str(), __FILE__, __LINE__);
    // check rule

    set<string> rewardNFTList;
    auto queryRewardList = query_list_result["data"]["rewardlists"];
    auto queryList = queryRewardList.array_items()[0]["list"];
    for (auto item : queryList.array_items()) {
        rewardNFTList.insert(item.string_value());
    }

    vector<string> rewardUserLists;
    auto queryNFTs = query_nft_result["data"]["interchainnftreceives"];
    ocall_print_string(queryNFTs.dump().c_str(), __FILE__, __LINE__);
    for (auto NFT : queryNFTs.array_items()) {
        ocall_print_string(NFT.dump().c_str(), __FILE__, __LINE__);
        if (rewardNFTList.find(NFT["class_id"].string_value()) != rewardNFTList.end()) {
            rewardUserLists.push_back(NFT["receiver"].string_value());
        }
    }

    for (auto s : rewardNFTList) {
        ocall_print_string(s.c_str(), __FILE__, __LINE__);
    }

    merkle::TreeT<32, sha256_sgx> tree;

    for (auto s : rewardUserLists) {
        ocall_print_string(s.c_str(), __FILE__, __LINE__);
        uint8_t hash[32];
        sgx_sha256_msg((unsigned char*)s.c_str(), s.length(), &hash);
        merkle::HashT<32> merkleNode(hash);
        ocall_print_string(merkleNode.to_string().c_str(), __FILE__, __LINE__);
        tree.insert(merkleNode);
    }

    auto root = tree.root();
    ocall_print_string(root.to_string().c_str(), __FILE__, __LINE__);

    memcpy(&request_context->result_bytes, root.bytes, 32);

    // TODO build rule check result
    ocall_print_string("exit EvaluateRule", __FILE__, __LINE__);
    return RuleEnclaveStatus::kOK;
}