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

struct PiecePosition {
    int row;
    int column;
};

class Piece {
public:
    Piece(PieceType type, PieceColour colour);

private:
    PieceType type;
    PiecePosition position;
    PieceColour colour;
};