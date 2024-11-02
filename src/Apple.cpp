#include "Apple.h"


void Apple::setPosition(const std::pair<unsigned int, unsigned int> &newPosition) {
    position = newPosition;
}


std::pair<unsigned int, unsigned> Apple::getPosition() const {
    return position;
}
