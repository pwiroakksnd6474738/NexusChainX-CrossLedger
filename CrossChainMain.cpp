#include <iostream>
#include "CrossChainBridge.h"
#include "CrossChainCrypto.h"

int main() {
    CrossChainBridge bridge;
    ChainNodeInfo eth_info = {
        "ETH_MAINNET",
        "https://eth-rpc.com",
        1,
        19000000,
        "PoS"
    };

    ChainNodeInfo bsc_info = {
        "BSC_MAINNET",
        "https://bsc-rpc.com",
        2,
        35000000,
        "PoSA"
    };

    bridge.init_bridge("ETH_MAINNET", eth_info);
    bridge.init_bridge("BSC_MAINNET", bsc_info);
    bridge.add_bridge_route("ETH_MAINNET", "BSC_MAINNET");

    auto hash = CrossChainCrypto::sha256_hash("CrossChainTransferTest");
    std::cout << "CrossChain Framework Initialized Successfully" << std::endl;
    std::cout << "SHA256 Test Hash: " << static_cast<int>(hash[0]) << "..." << std::endl;

    return 0;
}
