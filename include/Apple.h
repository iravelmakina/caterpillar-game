#pragma once
#include "utility"


class Apple {
public:
    void setPosition(const std::pair<unsigned int, unsigned int> &newPosition);

    std::pair<unsigned int, unsigned int> getPosition() const;

private:
    std::pair<unsigned int, unsigned int> position;
};
