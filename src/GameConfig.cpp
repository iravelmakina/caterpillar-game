#include "GameConfig.h"
#include <cmath>


GameConfig::GameConfig(const unsigned int initialWindowWidth, const unsigned int initialCellSize, const unsigned int initialFPS, const std::string &initialWindowTitle)
    : windowWidth(initialWindowWidth), cellSize(initialCellSize), fps(initialFPS), windowTitle(initialWindowTitle) {

    gridSize = windowWidth / cellSize;
    windowWidth = gridSize * cellSize;


    scoreBoardHeight = static_cast<unsigned int>(std::round(windowWidth * 0.1));

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


unsigned int GameConfig::getFPS() const {
    return fps;
}


const std::string& GameConfig::getWindowTitle() const {
    return windowTitle;
}
