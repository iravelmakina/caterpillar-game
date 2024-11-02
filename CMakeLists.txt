cmake_minimum_required(VERSION 3.29)
project(snake_game)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(snake_game
        src/Apple.cpp
        src/Snake.cpp
        src/Map.cpp
        src/SnakeGame.cpp
        src/InputHandler.cpp
)

set(SFML_DIR "/opt/homebrew/Cellar/sfml/2.6.1/lib/cmake/SFML")
find_package(SFML 2.6.1 COMPONENTS system window graphics network audio REQUIRED)
target_link_libraries(snake_game sfml-window)