#include "GameConfig.h"
#include <cmath>


GameConfig::GameConfig(const unsigned int initialWindowWidth, const unsigned int initialCellSize)
    : windowWidth(initialWindowWidth), cellSize(initialCellSize) {

    gridSize = windowWidth / cellSize;
    windowWidth = gridSize * cellSize;


    scoreBoardHeight = static_cast<unsigned int>(std::round(windowWidth * 0.12));

    windowHeight = windowWidth + scoreBoardHeight;
}


unsigned int GameConfig::getWindowWidth() const {
    return windowWidth;
}

unsigned int GameConfig::getWindowHeight() const {
    return windowHeight;
}


unsigned int GameConfig::getCellSize() const {
    return cellSize;
}


unsigned int GameConfig::getGridSize() const {
    return gridSize;
}


unsigned int GameConfig::getScoreBoardHeight() const {
    return scoreBoardHeight;
}
