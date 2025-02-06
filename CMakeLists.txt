cmake_minimum_required(VERSION 3.10)

project(pong)

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)

add_executable(pong main.cpp "geometry/Vec2.cpp" "utils/WindowUtils.cpp" "utils/RendererUtils.cpp" "entities/Ball.cpp" "entities/Paddle.cpp" "elements/Counter.cpp" "elements/Label.cpp" "game/Player.cpp" "game/Game.cpp" "utils/LogUtils.cpp")
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

target_link_libraries(
	pong 
	PRIVATE
	SDL2::SDL2
	SDL2::SDL2main
	SDL2_ttf::SDL2_ttf
)