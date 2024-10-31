cmake_minimum_required(VERSION 3.29)
project(snake_game)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(snake_game
        src/Apple.cpp
        src/Snake.cpp)
