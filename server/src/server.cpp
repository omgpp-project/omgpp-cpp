#include <cstdint>
#include <string>
#include <memory>

#include "server.hpp"
#include "internal.hpp"


omgpp::Server::Server(const std::string& ip, const uint16_t port)
    : actual_server(internal::server_create(ip.c_str(), port), internal::server_destroy)
{
}
