#include "Map.h"
#include "BlockFactory.h"


Map::Map(unsigned int width, unsigned int height, const unsigned int blockCount) : size(width, height),
                                                                                   grid(height, std::vector<char>(width, ' ')) {
    generateRandomWallBlocks(blockCount);
}


void Map::reset(const unsigned int wallBlockCount) {
    grid = std::vector<std::vector<char> >(size.second, std::vector<char>(size.first, ' '));
    walls.clear();
    generateRandomWallBlocks(wallBlockCount);
}


std::pair<unsigned int, unsigned int> Map::getSize() const {
    return size;
}


std::vector<std::pair<unsigned int, unsigned int>> &Map::getWallPositions() {
    return walls;
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
        const std::unique_ptr<Block> block = BlockFactory::createBlock();

        const unsigned int startX = std::rand() % size.first;
        const unsigned int startY = std::rand() % size.second;

        std::vector<std::pair<unsigned int, unsigned int>> newBlockPositions = block->generatePositions(startX, startY, size.first, size.second);

        if (!isBlockOverlap(newBlockPositions)) {
            for (const std::pair<unsigned int, unsigned int> &position: newBlockPositions) {
                addWall(position);
            }
            count++;
        }
    }
}


bool Map::isBlockOverlap(const std::vector<std::pair<unsigned int, unsigned int> > &block) const {
    for (const std::pair<unsigned int, unsigned int> &position: block) {
        if (isWall(position)) {
            return true;
        }
    }
    return false;
}
