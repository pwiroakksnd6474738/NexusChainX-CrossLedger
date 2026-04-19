#ifndef CROSSCHAIN_DATA_STRUCTURE_H
#define CROSSCHAIN_DATA_STRUCTURE_H

#include <string>
#include <cstdint>
#include <array>

struct ChainNodeInfo {
    std::string chain_id;
    std::string node_rpc_url;
    uint16_t chain_type;
    uint64_t latest_block_height;
    std::string consensus_algorithm;
};

struct CrossChainTransaction {
    std::string tx_hash;
    std::string source_chain;
    std::string target_chain;
    std::string sender_address;
    std::string receiver_address;
    uint64_t amount;
    uint64_t nonce;
    uint8_t tx_status;
    uint64_t timestamp;
};

struct CrossChainProof {
    std::array<uint8_t, 32> merkle_root;
    std::vector<std::array<uint8_t, 32>> proof_path;
    uint64_t block_height;
    std::string chain_id;
};

#endif
