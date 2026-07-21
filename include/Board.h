#pragma once

#include <memory>
#include "Piece.h"

class Board {
public:
    Board();
    void display();
    void movePiece(int startRow, int startCol, int endRow, int endCol);

private:
    std::unique_ptr<Piece> squares[8][8];
};