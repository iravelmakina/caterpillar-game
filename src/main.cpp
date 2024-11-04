#include <SFML/Graphics.hpp>

#include "GameConfig.h"
#include "GraphicsRenderer.h"
#include "InputHandler.h"
#include "SnakeGame.h"


int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // make singleton, patterns, namespace for input
    const GameConfig config(750, 25);
    sf::RenderWindow window(sf::VideoMode(config.getWindowWidth(), config.getWindowHeight()), "Caterpillar Game",
                            sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(10);
    GraphicsRenderer& gRenderer = GraphicsRenderer::getInstance(window, config.getCellSize(), config.getScoreBoardHeight());
    SoundRenderer& sRenderer = SoundRenderer::getInstance();
    SnakeGame& game = SnakeGame::getInstance(config.getGridSize(), config.getGridSize(), &gRenderer, &sRenderer);;

    while (window.isOpen()) {
        InputHandler::handleInput(game, window);
        game.update();
        game.render();
        if (!game) {
            window.close();
        }
    }
    return 0;
}
