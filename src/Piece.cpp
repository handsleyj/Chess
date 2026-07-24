#include "../include/Piece.h"

Piece::Piece(PieceType type, PieceColour colour) 
    : type(type), colour(colour)
{
}

PieceType Piece::getType() const {
    return this->type;
}

PieceColour Piece::getColour() const {
    return this-> colour;
}