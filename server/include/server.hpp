#pragma once

#include <cstdint>
#include <string>
#include <memory>

namespace omgpp
{
    class Server
    {
    public:
        Server(const std::string& ip, const uint16_t port);
        Server(const Server& other) = delete;
        Server(Server&& other) = delete;

        ~Server() = default;

        // TODO

    private:
        std::unique_ptr<void, void(*)(void*)> actual_server;
    };
}
