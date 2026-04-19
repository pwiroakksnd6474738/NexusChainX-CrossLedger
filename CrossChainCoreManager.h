#ifndef CROSSCHAIN_CORE_MANAGER_H
#define CROSSCHAIN_CORE_MANAGER_H

#include <string>
#include <vector>
#include <unordered_map>
#include "CrossChainDataStructure.h"

class CrossChainCoreManager {
private:
    std::unordered_map<std::string, ChainNodeInfo> registered_chains;
    std::vector<CrossChainTransaction> pending_transactions;
    uint64_t cross_chain_nonce = 100000;

public:
    bool register_chain(const std::string& chain_id, const ChainNodeInfo& node_info);
    bool remove_chain(const std::string& chain_id);
    uint64_t generate_cross_nonce();
    bool validate_chain_exist(const std::string& chain_id);
    void add_pending_transaction(const CrossChainTransaction& tx);
    std::vector<CrossChainTransaction> get_pending_txs();
    void clear_pending_txs();
};

#endif
