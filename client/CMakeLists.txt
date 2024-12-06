project(client)

add_library(omgpp-client STATIC
)
target_link_libraries(omgpp-client client_server)
