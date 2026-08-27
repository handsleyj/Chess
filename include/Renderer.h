#pragma once

#include "Board.h"
#include <SFML/Graphics.hpp>

#define BOARD_SIZE 640.0f
#define BOARD_DIMENSION 8
#define SQUARE_SIZE (BOARD_SIZE / BOARD_DIMENSION)

class Renderer {
public:
    Renderer(unsigned int windowSize = 800);
    void run(Board &board);
    void drawBoard();
    void drawPieces(Board &board);
    sf::Vector2f boardToScreen(int row, int col) const;

private:
    sf::RenderWindow window;
    sf::Color bgColour;
    sf::Color lightSquareColour;
    sf::Color darkSquareColour;

    sf::Texture whiteSquareTexture;
    sf::Texture blackSquareTexture;

    sf::Texture whitePawnTexture;
    sf::Texture blackPawnTexture;

    sf::Texture whiteRookTexture;
    sf::Texture blackRookTexture;
};