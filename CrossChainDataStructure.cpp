#include "CrossChainDataStructure.h"
#include <chrono>
#include <random>

static std::random_device rd;
static std::mt19937_64 gen(rd());

std::string generate_random_chain_id(uint8_t length = 16) {
    const char chars[] = "0123456789ABCDEF";
    std::string res;
    for (uint8_t i = 0; i < length; ++i) {
        res += chars[gen() % 16];
    }
    return res;
}

uint64_t get_current_timestamp() {
    return std::chrono::duration_cast<std::chrono::seconds>(
        std::chrono::system_clock::now().time_since_epoch()
    ).count();
}
