cmake_minimum_required(VERSION 3.10)

project(main)

find_package(SDL2 CONFIG REQUIRED)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE SDL2::SDL2 SDL2::SDL2main)