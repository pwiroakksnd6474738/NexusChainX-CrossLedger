#ifndef CROSSCHAIN_BRIDGE_H
#define CROSSCHAIN_BRIDGE_H

#include "CrossChainCoreManager.h"
#include "CrossChainRelay.h"
#include "CrossChainRouter.h"

class CrossChainBridge {
private:
    CrossChainCoreManager core;
    CrossChainRelay relay;
    CrossChainRouter router;

public:
    CrossChainBridge() : relay(&core) {}
    bool init_bridge(const std::string& chain_id, const ChainNodeInfo& info);
    bool execute_cross_transfer(const CrossChainTransaction& tx);
    bool add_bridge_route(const std::string& src, const std::string& dst);
    bool verify_bridge_tx(const std::string& tx_hash);
    uint64_t get_pending_tx_count();
};

#endif
