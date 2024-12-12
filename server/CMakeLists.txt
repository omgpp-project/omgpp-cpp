project(server)

include_directories(include)
add_subdirectory(src)

add_library(omgpp-server STATIC
    ${SERVER_SOURCES}
)
target_link_libraries(omgpp-server client_server)
