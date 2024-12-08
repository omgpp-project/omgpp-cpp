project(client)

include_directories(include)
add_subdirectory(src)

add_library(omgpp-client STATIC
    ${CLIENT_SOURCES}
)
target_link_libraries(omgpp-client client_server)
