#include "../include/Piece.h"
#include <cmath>

Piece::Piece(PieceType type, PieceColour colour) 
    : type(type), colour(colour)
{
    this->hasMoved = false;
}

PieceType Piece::getType() const {
    return this->type;
}

PieceColour Piece::getColour() const {
    return this-> colour;
}

/* Returns true when a piece can move in a certain pattern */
bool Piece::canMove(Coordinate start, Coordinate end) const {
    /* Check that the coordinates are not the same */
    if ((start.row == end.row) && (start.column == end.column)) {
        return false;
    }
    
    switch (this->type)
    {
        /* Pawn */
        case PieceType::PAWN: {
            if (this->getColour() == PieceColour::WHITE) {
                /* Pawn can move two spaces if it is the first move */
                if (!this->hasMoved) {
                    return (
                        (start.column == end.column && start.row - end.row == 1) ||
                        (start.column == end.column && start.row - end.row == 2) ||
                        (abs(start.column - end.column) == 1 && start.row - end.row == 1)
                    );
                }
                return (
                    (start.column == end.column && start.row - end.row == 1) ||
                    (abs(start.column - end.column) == 1 && start.row - end.row == 1)
                );
            }
            else {
                if (!this->hasMoved) {
                    return (
                        (start.column == end.column && start.row - end.row == -1) ||
                        (start.column == end.column && start.row - end.row == -2) ||
                        (abs(start.column - end.column) == 1 && start.row - end.row == -1)
                    );
                }
                return (
                    (start.column == end.column && start.row - end.row == -1) ||
                    (abs(start.column - end.column) == 1 && start.row - end.row == -1)
                );
            }
        }
        
        /* Rook - can only move in straight lines*/
        case PieceType::ROOK:
            return (start.row == end.row || start.column == end.column);
        
        /* Knight - can move in L-shapes */
        case PieceType::KNIGHT:
            return (
                (abs(start.row - end.row) == 2 && abs(start.column - end.column) == 1) ||
                (abs(start.row - end.row) == 1 && abs(start.column - end.column) == 2) 
            );
        
        /* Bishop - can only move diagonally */
        case PieceType::BISHOP:
            return (abs(start.row - end.row) == abs(start.column - end.column));

        /* Queen - can move straight or diagonally */
        case PieceType::QUEEN:
            return (
                start.row == end.row || 
                start.column == end.column ||
                (abs(start.row - end.row) == abs(start.column - end.column))
            );
        
        /* King - can move only 1 square in any direction */
        case PieceType::KING: {
            int rowDiff = abs(start.row - end.row);
            int columnDiff = abs(start.column - end.column);  
            
            return (
                rowDiff <= 1 &&
                columnDiff <= 1
            );
        }
        
        default:
            return false;
    }
}

void Piece::setHasMoved(bool val) {
    this->hasMoved = val;
}