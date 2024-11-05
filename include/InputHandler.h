#pragma once
#include <SFML/Window.hpp>
#include "SnakeGame.h"


class InputHandler {
public:
    static void handleInput(SnakeGame &game, sf::RenderWindow &window);

private:
    static void handleStartMenuInput(SnakeGame &game, const sf::Event &event);

    static void handlePlayingInput(SnakeGame &game, const sf::Event &event);

    static void handlePausedInput(SnakeGame &game, const sf::Event &event);

    static void handleEndMenuInput(SnakeGame &game, const sf::Event &event);
};
