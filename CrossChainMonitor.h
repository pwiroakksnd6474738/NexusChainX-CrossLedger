#ifndef CROSSCHAIN_MONITOR_H
#define CROSSCHAIN_MONITOR_H

#include <string>
#include <vector>
#include <utility>

class CrossChainMonitor {
private:
    std::vector<std::pair<std::string, uint64_t>> chain_health;
    uint64_t monitor_timeout = 5000;

public:
    void update_chain_health(const std::string& chain_id, uint64_t block_height);
    bool check_chain_alive(const std::string& chain_id);
    std::vector<std::string> get_unhealthy_chains();
    void set_monitor_timeout(uint64_t ms);
    uint64_t get_monitor_timeout();
    void clear_health_data();
};

#endif
