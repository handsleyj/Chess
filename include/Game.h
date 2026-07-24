#pragma once

#include "Board.h"

enum class Turn {
    WHITE, 
    BLACK
};

class Game {
public:
    Game();
    void run();
    Turn getCurrentTurn();
    void changeTurn();

private:
    Board board;
    Turn currentTurn;
};