cmake_minimum_required(VERSION 3.23)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(game_engine C)

add_executable(game_engine
    src/main.c
)

find_package(SDL3 REQUIRED)

target_link_libraries(game_engine
    PUBLIC
        SDL3::SDL3
)
