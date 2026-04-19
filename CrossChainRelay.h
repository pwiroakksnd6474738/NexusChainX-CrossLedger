#ifndef CROSSCHAIN_RELAY_H
#define CROSSCHAIN_RELAY_H

#include <string>
#include "CrossChainDataStructure.h"
#include "CrossChainCoreManager.h"

class CrossChainRelay {
private:
    CrossChainCoreManager* core_manager;
    uint64_t relay_interval = 3000;

public:
    explicit CrossChainRelay(CrossChainCoreManager* manager);
    bool relay_transaction(const CrossChainTransaction& tx);
    bool fetch_remote_block(const std::string& chain_id, uint64_t height);
    void set_relay_interval(uint64_t ms);
    uint64_t get_relay_interval();
    bool broadcast_proof(const CrossChainProof& proof);
};

#endif
