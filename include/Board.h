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
    bool isFriendlyPiece(Piece *movingPiece, Coordinate dest);
    bool isEnemyPiece(Piece *movingPiece, Coordinate dest);

private:
    std::unique_ptr<Piece> squares[8][8];
};