cmake_minimum_required(VERSION 3.10)

project(game)

find_package(SDL2 REQUIRED)

add_executable(game main.cpp "utils/Vec2.cpp" "utils/WindowUtils.cpp")

target_link_libraries(
	game 
	PRIVATE 
	SDL2::SDL2
	SDL2::SDL2main
)