#ifndef CROSSCHAIN_CRYPTO_H
#define CROSSCHAIN_CRYPTO_H

#include <string>
#include <vector>
#include <array>

class CrossChainCrypto {
public:
    static std::array<uint8_t, 32> sha256_hash(const std::string& input);
    static std::string sign_data(const std::string& private_key, const std::array<uint8_t, 32>& hash);
    static bool verify_signature(const std::string& public_key, const std::array<uint8_t, 32>& hash, const std::string& signature);
    static std::vector<uint8_t> aes_encrypt(const std::vector<uint8_t>& data, const std::array<uint8_t, 16>& key);
    static std::vector<uint8_t> aes_decrypt(const std::vector<uint8_t>& data, const std::array<uint8_t, 16>& key);
};

#endif
