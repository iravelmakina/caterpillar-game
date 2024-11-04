#pragma once
#include <SFML/Graphics.hpp>


class GraphicsRenderer {
public:
    static GraphicsRenderer &getInstance(sf::RenderWindow &window, unsigned int cellSize,
                                         unsigned int scoreBoardHeight);

    GraphicsRenderer(GraphicsRenderer &other) = delete;

    GraphicsRenderer &operator=(GraphicsRenderer &other) = delete;

    void renderGame(const std::pair<unsigned int, unsigned int> &headPosition,
                    const std::vector<std::pair<unsigned int, unsigned int> > &bodyPositions,
                    const std::pair<unsigned int, unsigned int> &applePosition,
                    const std::vector<std::pair<unsigned int, unsigned int> > &wallPositions,
                    unsigned int currentScore, unsigned int bestScore) const;

    void renderStartMenu() const;

    void renderPauseMenu() const;

    void renderEndMenu(unsigned int score, unsigned int bestScore, bool isWinner) const;

private:
    GraphicsRenderer(sf::RenderWindow &window, unsigned int cellSize, unsigned int scoreBoardHeight);

    static std::unique_ptr<GraphicsRenderer> instance;

    sf::RenderWindow &window;
    sf::Font font;
    sf::Texture wallTexture;
    sf::Texture appleTexture;
    sf::Texture caterpillarBodyTexture;
    sf::Texture caterpillarHeadTexture;
    unsigned int cellSize;
    unsigned int scoreBoardHeight;


    void drawCaterpillar(const std::pair<unsigned int, unsigned int> &headPosition,
                         const std::vector<std::pair<unsigned int, unsigned int> > &
                         bodyPositions) const;

    void drawApple(const std::pair<unsigned int, unsigned int> &applePosition) const;

    void drawWalls(const std::vector<std::pair<unsigned int, unsigned int> > &wallPositions) const;

    void drawScoreBoard(unsigned int currentScore, unsigned int bestScore) const;

    void drawText(const std::string &textStr, float x, float y, unsigned int fontSize) const;

    void loadTextures();
};
