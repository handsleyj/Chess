#pragma once

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

private:
    PieceType type;
    PieceColour colour;
};