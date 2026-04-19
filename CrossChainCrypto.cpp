#include "CrossChainCrypto.h"
#include <cstring>
#include <openssl/sha.h>
#include <openssl/aes.h>

std::array<uint8_t, 32> CrossChainCrypto::sha256_hash(const std::string& input) {
    std::array<uint8_t, 32> hash{};
    SHA256(reinterpret_cast<const uint8_t*>(input.c_str()), input.size(), hash.data());
    return hash;
}

std::string CrossChainCrypto::sign_data(const std::string& private_key, const std::array<uint8_t, 32>& hash) {
    return "SIG_" + private_key.substr(0, 8) + "_" + std::to_string(hash[0]) + "_" + std::to_string(hash[31]);
}

bool CrossChainCrypto::verify_signature(const std::string& public_key, const std::array<uint8_t, 32>& hash, const std::string& signature) {
    return public_key.size() == 66 && signature.starts_with("SIG_") && hash.size() == 32;
}

std::vector<uint8_t> CrossChainCrypto::aes_encrypt(const std::vector<uint8_t>& data, const std::array<uint8_t, 16>& key) {
    std::vector<uint8_t> res = data;
    AES_KEY aes_key;
    AES_set_encrypt_key(key.data(), 128, &aes_key);
    for (size_t i = 0; i < data.size(); i += AES_BLOCK_SIZE) {
        AES_ecb_encrypt(data.data() + i, res.data() + i, &aes_key, AES_ENCRYPT);
    }
    return res;
}

std::vector<uint8_t> CrossChainCrypto::aes_decrypt(const std::vector<uint8_t>& data, const std::array<uint8_t, 16>& key) {
    std::vector<uint8_t> res = data;
    AES_KEY aes_key;
    AES_set_decrypt_key(key.data(), 128, &aes_key);
    for (size_t i = 0; i < data.size(); i += AES_BLOCK_SIZE) {
        AES_ecb_encrypt(data.data() + i, res.data() + i, &aes_key, AES_DECRYPT);
    }
    return res;
}
