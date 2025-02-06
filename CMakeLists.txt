cmake_minimum_required(VERSION 3.10)

project(game)

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)

add_executable(game main.cpp "geometry/Vec2.cpp" "utils/WindowUtils.cpp" "utils/RendererUtils.cpp" "entities/Ball.cpp" "entities/Paddle.cpp" "elements/Counter.cpp" "elements/Label.cpp")
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

target_link_libraries(
	game 
	PRIVATE 
	SDL2::SDL2
	SDL2::SDL2main
	SDL2_ttf::SDL2_ttf
)