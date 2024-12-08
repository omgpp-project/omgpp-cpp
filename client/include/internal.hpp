#pragma once

#include <cstdint>

namespace omgpp::internal
{
    struct Endpoint
    {
        uint8_t ipv6_octets[16];
        uint16_t port;
    };

    enum ConnectionState : int16_t
    {
        None = -1,
        Disconnected = 0,
        Disconnecting = 1,
        Connecting = 2,
        ConnectedUnverified = 3,
        Connected = 4,
    };

    using CallbackOnStateGhange = void (*)(Endpoint, ConnectionState);
    using CallbackOnMessage = void (*)(Endpoint, int64_t, const uint8_t*, uintptr_t);
    using CallbackOnRpc = void (*)(Endpoint, bool, int64_t, uint64_t, int64_t, const uint8_t*, uintptr_t);

    extern "C" void* client_create(const char* ip, uint16_t port);
    extern "C" void client_destroy(void* client);

    extern "C" void client_connect(void* client);
    extern "C" void client_disconnect(void* client);

    extern "C" void client_send(void* client, int64_t msg_type, const uint8_t* data, intptr_t offset, uintptr_t size);
    extern "C" void client_send_reliable(void* client, int64_t msg_type, const uint8_t* data, intptr_t offset, uintptr_t size);
    extern "C" void client_call_rpc(void* client, bool reliable, int64_t method_id, uint64_t request_id, int64_t arg_type, const uint8_t* arg_data, intptr_t arg_data_offset, uintptr_t arg_data_size);
    extern "C" void client_process(void* client);

    extern "C" void client_register_on_connection_state_change(void* client, CallbackOnStateGhange callback);
    extern "C" void client_register_on_message(void* client, CallbackOnMessage callback);
    extern "C" void client_register_on_rpc(void* client, CallbackOnRpc callback);
}
