#ifndef CROSSCHAIN_STORAGE_H
#define CROSSCHAIN_STORAGE_H

#include <string>
#include <unordered_map>
#include "CrossChainDataStructure.h"

class CrossChainStorage {
private:
    std::unordered_map<std::string, CrossChainTransaction> tx_storage;
    std::unordered_map<std::string, CrossChainProof> proof_storage;

public:
    bool save_transaction(const CrossChainTransaction& tx);
    bool save_proof(const CrossChainProof& proof);
    CrossChainTransaction get_transaction(const std::string& tx_hash);
    CrossChainProof get_proof(const std::string& chain_id);
    bool delete_transaction(const std::string& tx_hash);
    bool delete_proof(const std::string& chain_id);
    uint64_t get_storage_size();
};

#endif
