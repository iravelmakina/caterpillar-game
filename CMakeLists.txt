cmake_minimum_required(VERSION 3.29)
project(caterpillar_game)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(caterpillar-game src/main.cpp
        src/Apple.cpp
        src/Snake.cpp
        src/Block.cpp
        src/BlockFactory.cpp
        src/Map.cpp
        src/SnakeGame.cpp
        src/InputHandler.cpp
        src/GraphicsRenderer.cpp
        src/SoundRenderer.cpp
        src/GameConfig.cpp
)

set(SFML_DIR "/opt/homebrew/Cellar/sfml/2.6.1/lib/cmake/SFML")
find_package(SFML 2.6.1 COMPONENTS system window graphics audio REQUIRED)
target_link_libraries(caterpillar-game sfml-system sfml-window sfml-graphics sfml-audio)
