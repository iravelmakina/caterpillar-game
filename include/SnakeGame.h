#pragma once

#include "Map.h"
#include "Apple.h"
#include "Snake.h"
#include "GraphicsRenderer.h"
#include "SoundRenderer.h"


enum class State {
    START_MENU,
    PAUSED,
    PLAYING,
    END_MENU,
    EXIT
};


class SnakeGame {
public:
    static SnakeGame &getInstance(unsigned int width, unsigned int height, GraphicsRenderer *gRenderer,
                                  SoundRenderer *sRenderer);

    SnakeGame(SnakeGame &other) = delete;

    SnakeGame &operator=(SnakeGame &other) = delete;

    bool operator!() const;


    State getState() const;

    unsigned int getCurrentScore() const;

    unsigned int getBestScore() const;

    void changeDirection(Direction newDirection);


    void start();

    void pause();

    void resume();

    void exitGame();

    void reset();


    void update();

    void render();

private:
    SnakeGame(unsigned int width, unsigned int height, GraphicsRenderer &gRenderer, SoundRenderer &sRenderer);

    static std::unique_ptr<SnakeGame> instance;

    void placeApple();

    void checkCollisions();

    void handleAppleCollision();

    GraphicsRenderer &gRenderer;
    SoundRenderer &sRenderer;
    Map map;
    Snake snake;
    Apple apple;

    const unsigned int maxSnakeSize;
    unsigned int currentScore;
    unsigned int bestScore;
    bool isWinner;
    State currentState;
    State prevState;

    sf::Clock gameClock;
    sf::Time deltaTime;
    sf::Time moveInterval;
    sf::Time timeAccumulator;
};
