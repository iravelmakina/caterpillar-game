#pragma once
#include "iostream"


class Apple {
public:
    void setPosition(const std::pair<unsigned int, unsigned int> &newPosition);

    std::pair<unsigned int, unsigned int> getPosition();

private:
    std::pair<unsigned int, unsigned int> position;
};
