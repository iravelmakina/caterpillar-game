#pragma once
#include <vector>


enum class BlockType {
    SINGLE,
    HORIZONTAL,
    VERTICAL,
    L_SHAPE
};

class Map {
public:
    Map(unsigned int width, unsigned int height, unsigned int blockCount);

    void reset(unsigned int wallBlockCount);

    std::pair<unsigned int, unsigned int> getSize() const;

    bool withinBounds(const std::pair<unsigned int, unsigned int> &position) const;

    bool isWall(const std::pair<unsigned int, unsigned int> &position) const;

    void addWall(const std::pair<unsigned int, unsigned int> &position);

    void generateRandomWallBlocks(unsigned int blockCount);

private:
    std::pair<unsigned int, unsigned int> size;
    std::vector<std::pair<unsigned int, unsigned int> > walls;
    std::vector<std::vector<char> > grid;

    std::vector<std::pair<unsigned int, unsigned int> > generateRandomWallBlock() const;

    bool isBlockOverlap(const std::vector<std::pair<unsigned int, unsigned> > &block) const;
};
