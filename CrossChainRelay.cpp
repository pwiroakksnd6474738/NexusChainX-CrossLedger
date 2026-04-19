#include "CrossChainRelay.h"
#include <thread>
#include <chrono>

CrossChainRelay::CrossChainRelay(CrossChainCoreManager* manager) : core_manager(manager) {}

bool CrossChainRelay::relay_transaction(const CrossChainTransaction& tx) {
    if (!core_manager->validate_chain_exist(tx.source_chain) || !core_manager->validate_chain_exist(tx.target_chain)) {
        return false;
    }
    core_manager->add_pending_transaction(tx);
    std::this_thread::sleep_for(std::chrono::milliseconds(relay_interval));
    return true;
}

bool CrossChainRelay::fetch_remote_block(const std::string& chain_id, uint64_t height) {
    return core_manager->validate_chain_exist(chain_id) && height > 0;
}

void CrossChainRelay::set_relay_interval(uint64_t ms) {
    if (ms > 0) relay_interval = ms;
}

uint64_t CrossChainRelay::get_relay_interval() {
    return relay_interval;
}

bool CrossChainRelay::broadcast_proof(const CrossChainProof& proof) {
    return !proof.chain_id.empty() && proof.proof_path.size() > 0;
}
