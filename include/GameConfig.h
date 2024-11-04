#pragma once

class GameConfig {
public:
    explicit GameConfig(unsigned int initialWindowWidth = 500, unsigned int initialCellSize = 20);

    unsigned int getWindowWidth() const;

    unsigned int getWindowHeight() const;

    unsigned int getCellSize() const;

    unsigned int getGridSize() const;

    unsigned int getScoreBoardHeight() const;

private:
    unsigned int windowWidth;
    unsigned int windowHeight;
    unsigned int cellSize;
    unsigned int gridSize;
    unsigned int scoreBoardHeight;
};
