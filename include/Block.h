#pragma once
#include <vector>


class Block {
public:
    virtual ~Block() = default;

    virtual std::vector<std::pair<unsigned int, unsigned int>> generatePositions(
        unsigned int startX, unsigned int startY, unsigned int width, unsigned int height) const = 0;
};


class SingleBlock final : public Block {
public:
    std::vector<std::pair<unsigned int, unsigned int>> generatePositions(
        unsigned int startX, unsigned int startY, unsigned int width, unsigned int height) const override;
};


class HorizontalBlock final : public Block {
public:
    std::vector<std::pair<unsigned int, unsigned int>> generatePositions(
        unsigned int startX, unsigned int startY, unsigned int width, unsigned int height) const override;
};


class VerticalBlock final : public Block {
public:
    std::vector<std::pair<unsigned int, unsigned int>> generatePositions(
        unsigned int startX, unsigned int startY, unsigned int width, unsigned int height) const override;
};


class LShapeBlock final : public Block {
public:
    std::vector<std::pair<unsigned int, unsigned int>> generatePositions(
        unsigned int startX, unsigned int startY, unsigned int width, unsigned int height) const override;
};
