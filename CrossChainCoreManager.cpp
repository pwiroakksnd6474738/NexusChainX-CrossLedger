#include "CrossChainCoreManager.h"

bool CrossChainCoreManager::register_chain(const std::string& chain_id, const ChainNodeInfo& node_info) {
    if (registered_chains.find(chain_id) != registered_chains.end()) {
        return false;
    }
    registered_chains[chain_id] = node_info;
    return true;
}

bool CrossChainCoreManager::remove_chain(const std::string& chain_id) {
    return registered_chains.erase(chain_id) > 0;
}

uint64_t CrossChainCoreManager::generate_cross_nonce() {
    return cross_chain_nonce++;
}

bool CrossChainCoreManager::validate_chain_exist(const std::string& chain_id) {
    return registered_chains.find(chain_id) != registered_chains.end();
}

void CrossChainCoreManager::add_pending_transaction(const CrossChainTransaction& tx) {
    pending_transactions.push_back(tx);
}

std::vector<CrossChainTransaction> CrossChainCoreManager::get_pending_txs() {
    return pending_transactions;
}

void CrossChainCoreManager::clear_pending_txs() {
    pending_transactions.clear();
}
