#pragma once

#include "Board.h"
#include <SFML/Graphics.hpp>

#define BOARD_SIZE 640.0f
#define BOARD_DIMENSION 8
#define SQUARE_SIZE (BOARD_SIZE / BOARD_DIMENSION)

class Renderer {
public:
    Renderer();
    void run(const Board &board);
    void drawBoard();

private:
    sf::RenderWindow window;
    sf::Color bgColour;
    sf::Color lightSquareColour;
    sf::Color darkSquareColour;
};