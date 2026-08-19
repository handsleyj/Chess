#pragma once

#include "Board.h"
#include <SFML/Graphics.hpp>

class Renderer {
public:
    void run();
    void drawBoard(const Board &board);
};