#pragma once

#include "Piece.h"
#include "Coordinate.h"
#include <memory>

class Board {
public:
    Board();
    void display();
    bool movePiece(Coordinate start, Coordinate end);
    Piece* getPieceFromCoordinate(Coordinate coord);

private:
    std::unique_ptr<Piece> squares[8][8];
};