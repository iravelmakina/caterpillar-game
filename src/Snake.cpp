#include "Snake.h"


Direction operator!(const Direction direction) {
    switch (direction) {
        case Direction::UP: return Direction::DOWN;
        case Direction::DOWN: return Direction::UP;
        case Direction::LEFT: return Direction::RIGHT;
        case Direction::RIGHT: return Direction::LEFT;
        default: break;
    }
    return direction;
}


Snake::Snake(unsigned int startX, unsigned int startY) : head({startX, startY}), direction(Direction::STOP),
                                                         growing(false) {
}


void Snake::reset(unsigned int startX, unsigned int startY) {
    head = {startX, startY};
    body.clear();
    direction = Direction::STOP;
    growing = false;
}

size_t Snake::size() const {
    return body.size();
}


void Snake::setDirection(const Direction &newDirection) {
    if (newDirection != !direction) {
        direction = newDirection;
    }
}


Direction Snake::getDirection() const {
    return direction;
}


void Snake::setHeadPosition(const std::pair<unsigned int, unsigned int> &newHeadPosition) {
    head = newHeadPosition;
}


std::pair<unsigned int, unsigned int> Snake::getHeadPosition() const {
    return head;
}


std::vector<std::pair<unsigned int, unsigned int> > &Snake::getBodyPositions() {
    return body;
}


bool Snake::collidesWithSelf() const {
    for (const std::pair<unsigned int, unsigned int> &part: body) {
        if (part == head) {
            return true;
        }
    }
    return false;
}


void Snake::grow() {
    growing = true;
}


void Snake::move() {
    if (direction == Direction::STOP) {
        return;
    }

    if (!body.empty() || growing) {
        body.insert(body.begin(), head);
        if (!growing) {
            body.pop_back();
        } else {
            growing = false;
        }
    }

    switch (direction) {
        case Direction::UP:
            head.second -= 1;
            break;
        case Direction::DOWN:
            head.second += 1;
            break;
        case Direction::LEFT:
            head.first -= 1;
            break;
        case Direction::RIGHT:
            head.first += 1;
            break;
        case Direction::STOP:
            break;
    }
}
