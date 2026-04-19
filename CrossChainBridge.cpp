#include "CrossChainBridge.h"

bool CrossChainBridge::init_bridge(const std::string& chain_id, const ChainNodeInfo& info) {
    return core.register_chain(chain_id, info);
}

bool CrossChainBridge::execute_cross_transfer(const CrossChainTransaction& tx) {
    if (!router.has_route(tx.source_chain, tx.target_chain)) return false;
    return relay.relay_transaction(tx);
}

bool CrossChainBridge::add_bridge_route(const std::string& src, const std::string& dst) {
    return router.add_route(src, dst);
}

bool CrossChainBridge::verify_bridge_tx(const std::string& tx_hash) {
    return !tx_hash.empty() && tx_hash.size() == 64;
}

uint64_t CrossChainBridge::get_pending_tx_count() {
    return core.get_pending_txs().size();
}
