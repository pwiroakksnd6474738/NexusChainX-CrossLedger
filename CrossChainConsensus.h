#ifndef CROSSCHAIN_CONSENSUS_H
#define CROSSCHAIN_CONSENSUS_H

#include <vector>
#include <string>
#include "CrossChainDataStructure.h"

class CrossChainConsensus {
private:
    std::vector<std::string> validator_nodes;
    uint8_t required_signatures = 2;

public:
    void add_validator(const std::string& node_addr);
    bool remove_validator(const std::string& node_addr);
    bool verify_consensus(const std::vector<std::string>& signatures);
    bool validate_cross_proof(const CrossChainProof& proof);
    uint8_t get_required_signatures();
    void set_required_signatures(uint8_t num);
};

#endif
