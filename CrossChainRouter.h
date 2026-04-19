#ifndef CROSSCHAIN_ROUTER_H
#define CROSSCHAIN_ROUTER_H

#include <string>
#include <unordered_map>
#include "CrossChainDataStructure.h"

class CrossChainRouter {
private:
    std::unordered_map<std::string, std::vector<std::string>> chain_routes;

public:
    bool add_route(const std::string& source_chain, const std::string& target_chain);
    bool remove_route(const std::string& source_chain, const std::string& target_chain);
    std::vector<std::string> get_routes(const std::string& source_chain);
    bool has_route(const std::string& source, const std::string& target);
    void clear_all_routes();
};

#endif
