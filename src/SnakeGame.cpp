#include "SnakeGame.h"


std::unique_ptr<SnakeGame> SnakeGame::instance = nullptr;


SnakeGame::SnakeGame(const unsigned int width, const unsigned int height, GraphicsRenderer &gRenderer, SoundRenderer &sRenderer) : gRenderer(gRenderer),
                                                                                                                        sRenderer(
                                                                                                                            sRenderer),
                                                                                                                        map(width, height,
                                                                                                                            width / 4),
                                                                                                                        snake(width / 2, height / 2), maxSnakeSize(
                                                                                                                            static_cast<unsigned int>(
                                                                                                                                0.65 * width * height)), currentScore(0),
                                                                                                                        bestScore(0),
                                                                                                                        isWinner(false), currentState(
                                                                                                                            State::START_MENU), prevState(State::START_MENU) {
    placeApple();
}


SnakeGame& SnakeGame::getInstance(const unsigned int width, const unsigned int height, GraphicsRenderer* gRenderer, SoundRenderer* sRenderer) {
    if (!instance) {
        if (!gRenderer) {
            throw std::runtime_error("Graphics renderer must be provided for the initial getInstance() call");
        }
        if (!sRenderer) {
            throw std::runtime_error("Sound renderer must be provided for the initial getInstance() call");
        }
        instance = std::unique_ptr<SnakeGame>(new SnakeGame(width, height, *gRenderer, *sRenderer));
    }

    return *instance;
}


bool SnakeGame::operator!() const {
    return currentState == State::EXIT;
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


void SnakeGame::changeDirection(const Direction newDirection) {
    snake.setDirection(newDirection);
}


void SnakeGame::start() {
    if (currentState == State::START_MENU || currentState == State::END_MENU) {
        currentState = State::PLAYING;
        sRenderer.playBackgroundMusic();
    }
}


void SnakeGame::pause() {
    if (currentState == State::PLAYING) {
        currentState = State::PAUSED;
        sRenderer.stopBackgroundMusic();
    }
}


void SnakeGame::resume() {
    if (currentState == State::PAUSED) {
        currentState = State::PLAYING;
        sRenderer.playBackgroundMusic();
    }
}


void SnakeGame::exitGame() {
    currentState = State::EXIT;
    sRenderer.stopBackgroundMusic();
}


void SnakeGame::reset() {
    currentScore = 0;
    isWinner = false;
    map.reset(map.getSize().first / 4);
    snake.reset(map.getSize().first / 2, map.getSize().second / 2);
    placeApple();
    currentState = State::START_MENU;
    sRenderer.stopBackgroundMusic();
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
        sRenderer.playCollisionSound();
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
    sRenderer.playEatSound();
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

    if (snake.size() + 1 >= maxSnakeSize) {
        isWinner = true;
        currentState = State::END_MENU;
    }
}


void SnakeGame::render() {
    switch (currentState) {
        case State::START_MENU:
            gRenderer.renderStartMenu();
            break;
        case State::PLAYING:
            gRenderer.renderGame(snake.getHeadPosition(), snake.getBodyPositions(), apple.getPosition(), map.getWallPositions(), currentScore, bestScore);
            break;
        case State::PAUSED:
            gRenderer.renderPauseMenu();
            break;
        case State::END_MENU:
            gRenderer.renderEndMenu(currentScore, bestScore, isWinner);
        break;
    }
}
