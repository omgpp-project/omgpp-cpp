project(server)

include_directories(include)

add_library(omgpp-server STATIC
)
target_link_libraries(omgpp-server client_server)
