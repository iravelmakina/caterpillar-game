#pragma once
#include <vector>


class Map {
public:
    Map(unsigned int width, unsigned int height, unsigned int blockCount);

    void reset(unsigned int wallBlockCount);

    std::pair<unsigned int, unsigned int> getSize() const;

    std::vector<std::pair<unsigned int, unsigned int>> &getWallPositions();


    bool withinBounds(const std::pair<unsigned int, unsigned int> &position) const;

    bool isWall(const std::pair<unsigned int, unsigned int> &position) const;

    void addWall(const std::pair<unsigned int, unsigned int> &position);

    void generateRandomWallBlocks(unsigned int blockCount);

private:
    std::pair<unsigned int, unsigned int> size;
    std::vector<std::pair<unsigned int, unsigned int> > walls;
    std::vector<std::vector<char> > grid;

    bool isBlockOverlap(const std::vector<std::pair<unsigned int, unsigned> > &block) const;
};
