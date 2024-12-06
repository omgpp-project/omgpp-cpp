cmake_minimum_required(VERSION 3.20.0)

project(omgpp-cpp
    VERSION 0.0.1
    LANGUAGES CXX
)
set(CMAKE_CXX_STANDARD 20)

find_library(OMGPP_LIB_PATH
    client_server
    PATHS external
)

add_subdirectory(client)
add_subdirectory(server)
