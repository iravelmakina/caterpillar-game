#include "Block.h"


std::vector<std::pair<unsigned int, unsigned int>> SingleBlock::generatePositions(
    unsigned int startX, unsigned int startY, unsigned int width, unsigned int height) const {
    return {{startX, startY}};
}


std::vector<std::pair<unsigned int, unsigned int>> HorizontalBlock::generatePositions(
    unsigned int startX, unsigned int startY, unsigned int width, unsigned int height) const {
    std::vector<std::pair<unsigned int, unsigned int>> positions = {{startX, startY}};
    if (startX + 1 < width) positions.push_back({startX + 1, startY});
    if (startX + 2 < width) positions.push_back({startX + 2, startY});
    return positions;
}


std::vector<std::pair<unsigned int, unsigned int>> VerticalBlock::generatePositions(
    unsigned int startX, unsigned int startY, unsigned int width, unsigned int height) const {
    std::vector<std::pair<unsigned int, unsigned int>> positions = {{startX, startY}};
    if (startY + 1 < height) positions.push_back({startX, startY + 1});
    if (startY + 2 < height) positions.push_back({startX, startY + 2});
    return positions;
}


std::vector<std::pair<unsigned int, unsigned int>> LShapeBlock::generatePositions(
    unsigned int startX, unsigned int startY, unsigned int width, unsigned int height) const {
    std::vector<std::pair<unsigned int, unsigned int>> positions = {{startX, startY}};
    if (startX + 1 < width) positions.push_back({startX + 1, startY});
    if (startY + 1 < height) positions.push_back({startX, startY + 1});
    return positions;
}
