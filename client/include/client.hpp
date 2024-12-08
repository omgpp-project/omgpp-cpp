#pragma once

#include <cstdint>
#include <string>
#include <memory>
#include <span>

namespace omgpp
{
    class Client
    {
    public:
        Client(const std::string& ip, const uint16_t port);
        Client(const Client& other) = delete;
        Client(Client&& other) = delete;

        ~Client() = default;

        void connect();
        void disconnect();

        void send(const int64_t message_type, const std::span<const uint8_t>& data);
        void send_reliable(const int64_t message_type, const std::span<const uint8_t>& data);

        void call_rpc();

        void process();

        void register_on_connection_state_change();
        void register_on_message();
        void register_on_rpc();

    private:
        const std::unique_ptr<void, void(*)(void*)> actual_client;
    };
}
