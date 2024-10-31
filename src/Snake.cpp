#include "Snake.h"


Snake::Snake(unsigned int startX, unsigned int startY) : head({startX, startY}), direction(Direction::STOP), growing(false) {}


void Snake::setDirection(const Direction &newDirection) {
    if ((direction == Direction::UP && newDirection != Direction::DOWN) ||
        (direction == Direction::DOWN && newDirection != Direction::UP) ||
        (direction == Direction::LEFT && newDirection != Direction::RIGHT) ||
        (direction == Direction::RIGHT && newDirection != Direction::LEFT)) {
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
    for (const std::pair<unsigned int, unsigned int>& part: body) {
        if (part == head) {
            return true;
        }
    }  return false;
}


void Snake::move() {
    if (direction == Direction::STOP) {
        return;
    }

    if (!body.empty()) {
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
