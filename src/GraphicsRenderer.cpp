#include "GraphicsRenderer.h"\



std::unique_ptr<GraphicsRenderer> GraphicsRenderer::instance = nullptr;


GraphicsRenderer& GraphicsRenderer::getInstance(sf::RenderWindow& window, const unsigned int cellSize, const unsigned int scoreBoardHeight) {
    if (!instance) {
        instance = std::unique_ptr<GraphicsRenderer>(new GraphicsRenderer(window, cellSize, scoreBoardHeight));
    }
    return *instance;
}


void GraphicsRenderer::renderGame(const std::pair<unsigned int, unsigned int> &headPosition,
                          const std::vector<std::pair<unsigned int, unsigned int>> &bodyPositions,
                          const std::pair<unsigned int, unsigned int> &applePosition,
                          const std::vector<std::pair<unsigned int, unsigned int>> &wallPositions,
                          const unsigned int currentScore, const unsigned int bestScore) const {
    window.clear(sf::Color(200, 200, 200));
    drawWalls(wallPositions);
    drawCaterpillar(headPosition, bodyPositions);
    drawApple(applePosition);
    drawScoreBoard(currentScore, bestScore);
    window.display();
}


void GraphicsRenderer::renderStartMenu() const {
    window.clear(sf::Color(200, 200, 200));

    drawText("Caterpillar Game", window.getSize().x * 0.5f, window.getSize().y * 0.35f, window.getSize().y * 0.08f);
    drawText("Press Space to Start", window.getSize().x * 0.5f, window.getSize().y * 0.55f, window.getSize().y * 0.05f);
    drawText("Press Q to Quit", window.getSize().x * 0.5f, window.getSize().y * 0.6f, window.getSize().y * 0.05f);

    window.display();
}


void GraphicsRenderer::renderPauseMenu() const {
    window.clear(sf::Color(200, 200, 200));

    drawText("Paused", window.getSize().x * 0.5f, window.getSize().y * 0.38f, window.getSize().y * 0.08f);
    drawText("Press Space to Resume", window.getSize().x * 0.5f, window.getSize().y * 0.5f, window.getSize().y * 0.05f);

    window.display();
}


void GraphicsRenderer::renderEndMenu(const unsigned int score, const unsigned int bestScore, const bool isWinner) const {
    window.clear(sf::Color(200, 200, 200));

    const std::string message = isWinner ? "You Win!" : "Game Over";
    drawText(message, window.getSize().x * 0.5f, window.getSize().y * 0.3f, window.getSize().y * 0.08f);
    drawText("Score: " + std::to_string(score), window.getSize().x * 0.5f, window.getSize().y * 0.5f, window.getSize().y * 0.05f);
    drawText("Best Score: " + std::to_string(bestScore), window.getSize().x * 0.5f, window.getSize().y * 0.55f, window.getSize().y * 0.05f);
    drawText("Press Space to see Menu", window.getSize().x * 0.5f, window.getSize().y * 0.65f, window.getSize().y * 0.05f);

    window.display();
}


void GraphicsRenderer::drawWalls(const std::vector<std::pair<unsigned int, unsigned int>> &wallPositions) const {
    for (const std::pair<unsigned int, unsigned int>& position: wallPositions) {
        sf::RectangleShape wall(sf::Vector2f(cellSize, cellSize));
        wall.setTexture(&wallTexture);
        wall.setPosition(position.first * cellSize, position.second * cellSize + scoreBoardHeight);
        window.draw(wall);
    }
}


void GraphicsRenderer::drawCaterpillar(const std::pair<unsigned int, unsigned int>& headPosition,
                         const std::vector<std::pair<unsigned int, unsigned int>>& bodyPositions) const {
    sf::RectangleShape headSegment(sf::Vector2f(cellSize, cellSize));
    headSegment.setTexture(&caterpillarHeadTexture);
    headSegment.setPosition(headPosition.first * cellSize, headPosition.second * cellSize + scoreBoardHeight);
    window.draw(headSegment);

    for (const auto& position : bodyPositions) {
        sf::RectangleShape segment(sf::Vector2f(cellSize, cellSize));
        segment.setTexture(&caterpillarBodyTexture);
        segment.setPosition(position.first * cellSize, position.second * cellSize + scoreBoardHeight);
        window.draw(segment);
    }
}



void GraphicsRenderer::drawApple(const std::pair<unsigned int, unsigned int> &applePosition) const {
    sf::RectangleShape apple(sf::Vector2f(cellSize, cellSize));
    apple.setTexture(&appleTexture);
    apple.setPosition(applePosition.first * cellSize, applePosition.second * cellSize + scoreBoardHeight);
    window.draw(apple);
}


void GraphicsRenderer::drawScoreBoard(const unsigned int currentScore, const unsigned int bestScore) const {
    sf::RectangleShape scoreBoardBackground(sf::Vector2f(window.getSize().x, scoreBoardHeight));
    scoreBoardBackground.setFillColor(sf::Color(220, 220, 220));
    scoreBoardBackground.setOutlineColor(sf::Color(0, 0, 0));
    scoreBoardBackground.setOutlineThickness(-3);
    scoreBoardBackground.setPosition(0, 0);
    window.draw(scoreBoardBackground);

    const unsigned int fontSize = static_cast<unsigned int>(scoreBoardHeight * 0.2f);

    drawText("CURRENT SCORE: " + std::to_string(currentScore), window.getSize().x * 0.2f,
             scoreBoardHeight / 2, fontSize);
    drawText("BEST SCORE: " + std::to_string(bestScore), window.getSize().x * 0.75f,
             scoreBoardHeight / 2, fontSize);
}


void GraphicsRenderer::drawText(const std::string &textStr, const float x, const float y, const unsigned int fontSize) const {
    sf::Text text;
    text.setFont(font);
    text.setString(textStr);
    text.setCharacterSize(fontSize);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);

    const sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.width / 2, textRect.height / 2);
    text.setPosition(x, y);

    window.draw(text);
}


GraphicsRenderer::GraphicsRenderer(sf::RenderWindow& window, const unsigned int cellSize, const unsigned int scoreBoardHeight)  : window(window), cellSize(cellSize), scoreBoardHeight(scoreBoardHeight) {
    loadTextures();
}


void GraphicsRenderer::loadTextures() {
    if (!font.loadFromFile("res/fonts/arial.ttf")) {
        throw std::runtime_error("Failed to load font");
    }
    if (!wallTexture.loadFromFile("res/imgs/block.png")) {
        throw std::runtime_error("Failed to load wall texture");
    }
    if (!appleTexture.loadFromFile("res/imgs/apple.png")) {
        throw std::runtime_error("Failed to load apple texture");
    }
    if (!caterpillarBodyTexture.loadFromFile("res/imgs/caterpillarBody.png")) {
        throw std::runtime_error("Failed to load apple texture");
    }
    if (!caterpillarHeadTexture.loadFromFile("res/imgs/caterpillarHead.png")) {
        throw std::runtime_error("Failed to load apple texture");
    }
}
