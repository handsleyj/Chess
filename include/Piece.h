#pragma once

#include "Coordinate.h"

enum class PieceType {
    PAWN = 0,
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING
};

enum class PieceColour {
    BLACK=0,
    WHITE
};

class Piece {
public:
    Piece(PieceType type, PieceColour colour);
    PieceType getType() const;
    PieceColour getColour() const;
    bool canMove(Coordinate start, Coordinate end) const;
    void setHasMoved(bool val);

private:
    PieceType type;
    PieceColour colour;
    bool hasMoved;
};