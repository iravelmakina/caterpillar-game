#pragma once
#include <Map.h>
#include <Apple.h>
#include <Snake.h>

enum class State {
    START_MENU,
    PAUSED,
    PLAYING,
    END_MENU,
    EXIT
};


class SnakeGame {
public:
    static SnakeGame &getInstance(unsigned int width, unsigned int height);

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

private:
    SnakeGame(unsigned int width, unsigned int height);

    SnakeGame(const SnakeGame &other) = delete;

    SnakeGame operator=(const SnakeGame &other) = delete;

    unsigned int maxSnakeSize;
    State currentState;
    State prevState;
    unsigned int currentScore;
    unsigned int bestScore;
    bool isWinner;
    Map map;
    Apple apple;
    Snake snake;

    void placeApple();

    void checkCollisions();

    void handleAppleCollision();
};
