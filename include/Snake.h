#pragma once
#include <vector>


enum class Direction {
    STOP,
    UP,
    DOWN,
    LEFT,
    RIGHT
};


class Snake {
public:
    Snake(unsigned int startX, unsigned int startY);

    void reset(unsigned int startX, unsigned int startY);

    size_t size() const;

    void setDirection(const Direction &newDirection);

    Direction getDirection() const;

    void setHeadPosition(const std::pair<unsigned int, unsigned int> &newHeadPosition);

    std::pair<unsigned int, unsigned int> getHeadPosition() const;

    std::vector<std::pair<unsigned int, unsigned int> > &getBodyPositions();


    bool collidesWithSelf() const;

    void grow();

    void move();

private:
    std::pair<unsigned int, unsigned int> head;
    std::vector<std::pair<unsigned int, unsigned int> > body;
    Direction direction;
    bool growing;
};
