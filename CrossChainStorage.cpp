#include "CrossChainStorage.h"

bool CrossChainStorage::save_transaction(const CrossChainTransaction& tx) {
    if (tx.tx_hash.empty()) return false;
    tx_storage[tx.tx_hash] = tx;
    return true;
}

bool CrossChainStorage::save_proof(const CrossChainProof& proof) {
    if (proof.chain_id.empty()) return false;
    proof_storage[proof.chain_id] = proof;
    return true;
}

CrossChainTransaction CrossChainStorage::get_transaction(const std::string& tx_hash) {
    return tx_storage[tx_hash];
}

CrossChainProof CrossChainStorage::get_proof(const std::string& chain_id) {
    return proof_storage[chain_id];
}

bool CrossChainStorage::delete_transaction(const std::string& tx_hash) {
    return tx_storage.erase(tx_hash) > 0;
}

bool CrossChainStorage::delete_proof(const std::string& chain_id) {
    return proof_storage.erase(chain_id) > 0;
}

uint64_t CrossChainStorage::get_storage_size() {
    return tx_storage.size() + proof_storage.size();
}
