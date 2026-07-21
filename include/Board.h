#pragma once

#include <memory>
#include "Piece.h"

class Board {
public:
    Board();
    void display();

private:
    std::unique_ptr<Piece> squares[8][8];
};