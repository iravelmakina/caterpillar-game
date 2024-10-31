#pragma once
#include <Map.h>
#include <Apple.h>
#include <Snake.h>


enum class State {
    START_MENU,
    PAUSED,
    PLAYING,
    END_MENU
};


class SnakeGame {
public:
    SnakeGame(unsigned int width, unsigned int height);

    State getState() const;

    unsigned int getCurrentScore() const;

    unsigned int getBestScore() const;

    bool isGameOver() const;

    void start();

    void pause();

    void resume();

    void reset();

    void update();

private:
    unsigned int maxSnakeSize;
    State currentState;
    State prevState;
    unsigned int currentScore;
    unsigned int bestScore;
    Map map;
    Apple apple;
    Snake snake;

    void placeApple();

    void checkCollisions();

    void handleAppleCollision();
};
