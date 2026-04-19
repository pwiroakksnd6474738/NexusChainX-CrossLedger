cmake_minimum_required(VERSION 3.20)
project(NexusChainX-CrossLedger)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenSSL REQUIRED)

include_directories(.)

add_executable(NexusChainX
    CrossChainMain.cpp
    CrossChainCoreManager.cpp
    CrossChainDataStructure.cpp
    CrossChainConsensus.cpp
    CrossChainCrypto.cpp
    CrossChainRelay.cpp
    CrossChainRouter.cpp
    CrossChainMonitor.cpp
    CrossChainStorage.cpp
    CrossChainBridge.cpp
)

target_link_libraries(NexusChainX OpenSSL::SSL OpenSSL::Crypto)
