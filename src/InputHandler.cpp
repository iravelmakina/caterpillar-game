#include "InputHandler.h"


void InputHandler::handleInput(SnakeGame &game, sf::RenderWindow &window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        switch (game.getState()) {
            case State::START_MENU:
                handleStartMenuInput(game, event);
                break;
            case State::PLAYING:
                handlePlayingInput(game, event);
                break;
            case State::PAUSED:
                handlePausedInput(game, event);
                break;
            case State::END_MENU:
                handleEndMenuInput(game, event);
                break;
            default:
                break;
        }
    }
}


void InputHandler::handleStartMenuInput(SnakeGame &game, const sf::Event &event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
        game.start();
    } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Q) {
        game.exitGame();
    }
}


void InputHandler::handlePlayingInput(SnakeGame &game, const sf::Event &event) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        game.changeDirection(Direction::UP);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        game.changeDirection(Direction::LEFT);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        game.changeDirection(Direction::DOWN);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        game.changeDirection(Direction::RIGHT);
    }

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
        game.pause();
    }
}


void InputHandler::handlePausedInput(SnakeGame &game, const sf::Event &event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
        game.resume();
    } else if (event.key.code == sf::Keyboard::Q) {
        game.reset();
    }
}


void InputHandler::handleEndMenuInput(SnakeGame &game, const sf::Event &event) {
    if (event.key.code == sf::Keyboard::Space) {
        game.reset();
    }
}
