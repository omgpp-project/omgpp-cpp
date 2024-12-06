#pragma once

#include <cstdint>

namespace omgpp::internal
{
    struct Uuid
    {
        uint8_t bytes[16];
    };
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

    using CallbackOnConnectRequested = bool (*)(Uuid, Endpoint);
    using CallbackOnConnectionChanged = void (*)(Uuid, Endpoint, ConnectionState);
    using CallbackOnMessage = void (*)(Uuid, Endpoint, int64_t, const uint8_t*, uintptr_t);
    using CallbackOnRpc = void (*)(Uuid, Endpoint, bool, int64_t, uint64_t, int64_t, const uint8_t*, uintptr_t);

    extern "C" void* server_create(const char* ip, uint16_t port);
    extern "C" void server_destroy(void* server);

    extern "C" void server_disconnect(void* server, const Uuid* uuid);

    extern "C" void server_send(void* server, const Uuid* uuid, int64_t msg_type, const uint8_t* data, intptr_t offset, uintptr_t size);
    extern "C" void server_send_reliable(void* server, const Uuid* uuid, int64_t msg_type, const uint8_t* data, intptr_t offset, uintptr_t size);
    extern "C" void server_broadcast(void* server, int64_t msg_type, const uint8_t* data, intptr_t offset, uintptr_t size);
    extern "C" void server_broadcast_reliable(void* server, int64_t msg_type, const uint8_t* data, intptr_t offset, uintptr_t size);
    extern "C" void server_call_rpc(void* server, const Uuid* client, bool reliable, int64_t method_id, uint64_t request_id, int64_t arg_type, const uint8_t* arg_data, intptr_t arg_data_offset, uintptr_t arg_data_size);
    extern "C" void server_call_rpc_broadcast(void* server, bool reliable, int64_t method_id, uint64_t request_id, int64_t arg_type, const uint8_t* arg_data, intptr_t arg_data_offset, uintptr_t arg_data_size);
    extern "C" void server_process(void* server);

    extern "C" void server_register_on_connect_requested(void* server, CallbackOnConnectRequested callback);
    extern "C" void server_register_on_connection_state_change(void* server, CallbackOnConnectionChanged callback);
    extern "C" void server_register_on_message(void* server, CallbackOnMessage callback);
    extern "C" void server_register_on_rpc(void* server, CallbackOnRpc callback);
}
