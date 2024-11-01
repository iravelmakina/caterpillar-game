#include "SnakeGame.h"


SnakeGame::SnakeGame(const unsigned int width, const unsigned int height) : map(width, height,
                                                                                width / 5),
                                                                            snake(width / 2, height / 2),
                                                                            maxSnakeSize(
                                                                                static_cast<unsigned int>(
                                                                                    0.75 * width * height)),
                                                                            currentState(
                                                                                State::START_MENU), prevState(State::START_MENU),
                                                                            currentScore(0),
                                                                            bestScore(0) {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // to main
    placeApple();
}


SnakeGame&::getInstance(const unsigned int width = 800, const unsigned int height = 600) {
    static SnakeGame instance(width, height);
    return instance;
}


State SnakeGame::getState() const {
    return currentState;
}


unsigned int SnakeGame::getCurrentScore() const {
    return currentScore;
}


unsigned int SnakeGame::getBestScore() const {
    return bestScore;
}


bool SnakeGame::isGameOver() const {
    return currentState == State::END_MENU;
}


void SnakeGame::changeDirection(const Direction newDirection) {
    snake.setDirection(newDirection);
}


void SnakeGame::start() {
    if (currentState == State::START_MENU || currentState == State::END_MENU) {
        currentState = State::PLAYING;
    }
}


void SnakeGame::pause() {
    if (currentState == State::PLAYING) {
        currentState = State::PAUSED;
    }
}


void SnakeGame::resume() {
    if (currentState == State::PAUSED) {
        currentState = State::PLAYING;
    }
}


void SnakeGame::exitGame() {
    currentState = State::EXIT;
}


void SnakeGame::reset() {
    currentScore = 0;
    map.reset(map.getSize().first / 10);
    snake.reset(map.getSize().first / 2, map.getSize().second / 2);
    placeApple();
    currentState = State::START_MENU;
}


void SnakeGame::placeApple() {
    std::pair<unsigned int, unsigned int> newPosition;

    do {
        newPosition.first = std::rand() % map.getSize().first;
        newPosition.second = std::rand() % map.getSize().second;
    } while (map.isWall(newPosition) || newPosition == snake.getHeadPosition() ||
             std::find(snake.getBodyPositions().begin(), snake.getBodyPositions().end(), newPosition) != snake.
             getBodyPositions().end());

    apple.setPosition(newPosition);
}


void SnakeGame::checkCollisions() {
    if (map.isWall(snake.getHeadPosition()) || snake.collidesWithSelf()) {
        if (currentScore > bestScore) {
            bestScore = currentScore;
        }
        currentState = State::END_MENU;
        return;
    }
    if (snake.getHeadPosition() == apple.getPosition()) {
        handleAppleCollision();
    }
}


void SnakeGame::handleAppleCollision() {
    snake.grow();
    currentScore += 10;
    placeApple();
}


void SnakeGame::update() {
    if (currentState != State::PLAYING) return;

    snake.move();

    std::pair<unsigned int, unsigned int> headPosition = snake.getHeadPosition();

    headPosition.first = (headPosition.first + map.getSize().first) % map.getSize().first;
    headPosition.second = (headPosition.second + map.getSize().second) % map.getSize().second;

    snake.setHeadPosition(headPosition);

    checkCollisions();

    if (snake.getBodyPositions().size() + 1 >= maxSnakeSize) {
        currentState = State::END_MENU;
    }
}
