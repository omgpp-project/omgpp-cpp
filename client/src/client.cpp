#include <cstdint>
#include <string>
#include <span>

#include "client.hpp"
#include "internal.hpp"

omgpp::Client::Client(const std::string& ip, const uint16_t port)
    : actual_client(internal::client_create(ip.c_str(), port), internal::client_destroy)
{
}

void omgpp::Client::connect()
{
    internal::client_connect(this->actual_client.get());
}

void omgpp::Client::disconnect()
{
    internal::client_connect(this->actual_client.get());
}

void omgpp::Client::send(const int64_t message_type,
                         const std::span<const uint8_t>& data)
{
    internal::client_send(this->actual_client.get(),
                          message_type, data.data(), 0, data.size());
}

void omgpp::Client::send_reliable(const int64_t message_type,
                                  const std::span<const uint8_t>& data)
{
    internal::client_send_reliable(this->actual_client.get(),
                                   message_type, data.data(), 0, data.size());
}

void omgpp::Client::call_rpc()
{
}

void omgpp::Client::process()
{
    internal::client_process(this->actual_client.get());
}

void omgpp::Client::register_on_connection_state_change()
{
}

void omgpp::Client::register_on_message()
{
}

void omgpp::Client::register_on_rpc()
{
}
