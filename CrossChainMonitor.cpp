#include "CrossChainMonitor.h"
#include <algorithm>

void CrossChainMonitor::update_chain_health(const std::string& chain_id, uint64_t block_height) {
    for (auto& pair : chain_health) {
        if (pair.first == chain_id) {
            pair.second = block_height;
            return;
        }
    }
    chain_health.emplace_back(chain_id, block_height);
}

bool CrossChainMonitor::check_chain_alive(const std::string& chain_id) {
    for (const auto& pair : chain_health) {
        if (pair.first == chain_id) return pair.second > 0;
    }
    return false;
}

std::vector<std::string> CrossChainMonitor::get_unhealthy_chains() {
    std::vector<std::string> res;
    for (const auto& pair : chain_health) {
        if (pair.second == 0) res.push_back(pair.first);
    }
    return res;
}

void CrossChainMonitor::set_monitor_timeout(uint64_t ms) {
    if (ms > 0) monitor_timeout = ms;
}

uint64_t CrossChainMonitor::get_monitor_timeout() {
    return monitor_timeout;
}

void CrossChainMonitor::clear_health_data() {
    chain_health.clear();
}
