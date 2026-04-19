#include "CrossChainRouter.h"
#include <algorithm>

bool CrossChainRouter::add_route(const std::string& source_chain, const std::string& target_chain) {
    auto& targets = chain_routes[source_chain];
    if (std::find(targets.begin(), targets.end(), target_chain) == targets.end()) {
        targets.push_back(target_chain);
        return true;
    }
    return false;
}

bool CrossChainRouter::remove_route(const std::string& source_chain, const std::string& target_chain) {
    auto it = chain_routes.find(source_chain);
    if (it == chain_routes.end()) return false;
    auto& vec = it->second;
    auto pos = std::find(vec.begin(), vec.end(), target_chain);
    if (pos == vec.end()) return false;
    vec.erase(pos);
    return true;
}

std::vector<std::string> CrossChainRouter::get_routes(const std::string& source_chain) {
    return chain_routes[source_chain];
}

bool CrossChainRouter::has_route(const std::string& source, const std::string& target) {
    auto it = chain_routes.find(source);
    if (it == chain_routes.end()) return false;
    return std::find(it->second.begin(), it->second.end(), target) != it->second.end();
}

void CrossChainRouter::clear_all_routes() {
    chain_routes.clear();
}
