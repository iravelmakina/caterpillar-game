#include "Map.h"


Map::Map(unsigned int width, unsigned int height, const unsigned int blockCount) : size(width, height),
    grid(height, std::vector<char>(width, ' ')) {
    generateRandomWallBlocks(blockCount);
}


void Map::reset(const unsigned int wallBlockCount) {
    grid = std::vector<std::vector<char> >(size.second, std::vector<char>(size.first, ' '));
    walls.clear();
    generateRandomWallBlocks(wallBlockCount);
}


std::vector<std::pair<unsigned int, unsigned int>> &Map::getWallPositions() {
    return walls;
}


std::pair<unsigned int, unsigned int> Map::getSize() const {
    return size;
}


bool Map::withinBounds(const std::pair<unsigned int, unsigned int> &position) const {
    return position.first < size.first && position.second < size.second;
}


bool Map::isWall(const std::pair<unsigned int, unsigned int> &position) const {
    return grid[position.second][position.first] == 'W';
}


void Map::addWall(const std::pair<unsigned int, unsigned int> &position) {
    walls.push_back(position);
    grid[position.second][position.first] = 'W';
}


void Map::generateRandomWallBlocks(const unsigned int blockCount) {
    unsigned int count = 0;

    while (count < blockCount) {
        std::vector<std::pair<unsigned int, unsigned int> > newBlock = generateRandomWallBlock();

        if (!isBlockOverlap(newBlock)) {
            for (const std::pair<unsigned int, unsigned int> &position: newBlock) {
                addWall(position);
            }
            count++;
        }
    }
}


std::vector<std::pair<unsigned int, unsigned int> > Map::generateRandomWallBlock() const {
    const BlockType blockType = static_cast<BlockType>(std::rand() % 4);
    unsigned int startX = std::rand() % size.first;
    unsigned int startY = std::rand() % size.second;

    std::vector<std::pair<unsigned int, unsigned int> > newBlock;

    switch (blockType) {
        case BlockType::SINGLE:
            newBlock.push_back({startX, startY});
            break;

        case BlockType::HORIZONTAL:
            if (withinBounds({startX, startY}) && withinBounds({startX + 1, startY})) {
                newBlock.push_back({startX, startY});
                newBlock.push_back({startX + 1, startY});
                if (withinBounds({startX + 2, startY})) {
                    newBlock.push_back({startX + 2, startY});
                }
            }
            break;

        case BlockType::VERTICAL:
            if (withinBounds({startX, startY}) && withinBounds({startX, startY + 1})) {
                newBlock.push_back({startX, startY});
                newBlock.push_back({startX, startY + 1});
                if (withinBounds({startX, startY + 2})) {
                    newBlock.push_back({startX, startY + 2});
                }
            }
            break;

        case BlockType::L_SHAPE:
            if (withinBounds({startX, startY}) && withinBounds({startX + 1, startY}) &&
                withinBounds({startX, startY + 1})) {
                newBlock.push_back({startX, startY});
                newBlock.push_back({startX + 1, startY});
                newBlock.push_back({startX, startY + 1});
            }
            break;
    }
    return newBlock;
}


bool Map::isBlockOverlap(const std::vector<std::pair<unsigned int, unsigned int> > &block) const {
    for (const std::pair<unsigned int, unsigned int> &position: block) {
        if (isWall(position)) {
            return true;
        }
    }
    return false;
}
