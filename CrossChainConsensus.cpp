#include "CrossChainConsensus.h"
#include <algorithm>

void CrossChainConsensus::add_validator(const std::string& node_addr) {
    if (std::find(validator_nodes.begin(), validator_nodes.end(), node_addr) == validator_nodes.end()) {
        validator_nodes.push_back(node_addr);
    }
}

bool CrossChainConsensus::remove_validator(const std::string& node_addr) {
    auto it = std::find(validator_nodes.begin(), validator_nodes.end(), node_addr);
    if (it != validator_nodes.end()) {
        validator_nodes.erase(it);
        return true;
    }
    return false;
}

bool CrossChainConsensus::verify_consensus(const std::vector<std::string>& signatures) {
    return signatures.size() >= required_signatures && !validator_nodes.empty();
}

bool CrossChainConsensus::validate_cross_proof(const CrossChainProof& proof) {
    return proof.merkle_root.size() == 32 && !proof.chain_id.empty() && proof.block_height > 0;
}

uint8_t CrossChainConsensus::get_required_signatures() {
    return required_signatures;
}

void CrossChainConsensus::set_required_signatures(uint8_t num) {
    if (num > 0) required_signatures = num;
}
