#include "../include/Board.h"
#include "../include/Coordinate.h"
#include <iostream>
#include <array>

/* Get the symbol to show for a given chess piece */
char getSymbol(const Piece &piece) {
    switch (piece.getType())
    {
        /* Pawn (P) */
        case PieceType::PAWN: 
            return piece.getColour() == PieceColour::WHITE ? 'P' : 'p';
        
        /* Rook (R) */
        case PieceType::ROOK:
            return piece.getColour() == PieceColour::WHITE ? 'R' : 'r';
        
        /* Knight (N) */
        case PieceType::KNIGHT:
            return piece.getColour() == PieceColour::WHITE ? 'N': 'n';
        
        /* Bishop (B) */
        case PieceType::BISHOP:
            return piece.getColour() == PieceColour::WHITE ? 'B': 'b';
        
        /* Queen (Q) */
        case PieceType::QUEEN:
            return piece.getColour() == PieceColour::WHITE ? 'Q' : 'q';
        
        /* King (K) */
        case PieceType::KING:
            return piece.getColour() == PieceColour::WHITE ? 'K' : 'k';
        
        default:
            return '?';
    }
}

/* To create the chess board array */
Board::Board() {
    /* The row for the furthest edges of the board */
    const std::array<PieceType, 8> edgeRow {
        PieceType::ROOK,
        PieceType::KNIGHT,
        PieceType::BISHOP,
        PieceType::QUEEN,
        PieceType::KING,
        PieceType::BISHOP,
        PieceType::KNIGHT,
        PieceType::ROOK
    };
    
    for (int row = 0; row < 8; row++) {
        /* Top edge row (BLACK) */
        if (row == 0) {
            for (int col = 0; col < 8; col++) {
                squares[row][col] = std::make_unique<Piece>(
                    edgeRow[col], 
                    PieceColour::BLACK
                );
            }
        }
        /* Top pawn row (BLACK) */
        else if (row == 1) {
            for (int col = 0; col < 8; col++) {
                squares[row][col] = std::make_unique<Piece>(
                    PieceType::PAWN, 
                    PieceColour::BLACK
                );
            }
        }
        /* Bottom pawn row (WHITE) */
        else if (row == 6) {
            for (int col = 0; col < 8; col++) {
                squares[row][col] = std::make_unique<Piece>(
                    PieceType::PAWN, 
                    PieceColour::WHITE
                );
            }
        }
        /* Bottom edge row (WHITE) */
        else if (row == 7) {
            for (int col = 0; col < 8; col++) {
                squares[row][col] = std::make_unique<Piece>(
                    edgeRow[col], 
                    PieceColour::WHITE
                );
            }
        }
        /* Empty rows*/
        else {
            for (int col = 0; col < 8; col++) {
                squares[row][col] = nullptr;
            }
        } 
    }
}

/* To display the chess board to the screen */
void Board::display() {
    /* Clear screen and move cursor to top left */
    std::cout << "\033[2J\033[H";

    /* Populate table */
    for (int row = 0; row < 8; row++) {

        std::cout << 8 - row << " | ";

        for (int col = 0; col < 8; col++) {
            if (squares[row][col] == nullptr) {
                std::cout << ". ";
            }
            else {
                std::cout << getSymbol(*squares[row][col]) << " ";
            }
        }
        std::cout << "\n";
    }

    /* Output grid coordinates */
    std::cout << "    a b c d e f g h\n";
}

/* Move a piece from one position on the board to another */
bool Board::movePiece(Coordinate start, Coordinate end) {
    Piece * pieceToMove = this->getPieceFromCoordinate(start);

    if (pieceToMove == nullptr) {
        return false;
    }

    if (!pieceToMove->canMove(start, end)) {
        return false;
    }

    if (this->isFriendlyPiece(pieceToMove, end)) {
        return false;
    }

    if (
        pieceToMove->getType() == PieceType::ROOK ||
        pieceToMove->getType() == PieceType::BISHOP ||
        pieceToMove->getType() == PieceType::QUEEN
    ) {
        if (!this->isPathClear(start, end)) {
            return false;
        }
    }

    squares[end.row][end.column] = std::move(squares[start.row][start.column]);
    
    squares[end.row][end.column]->setHasMoved(true);

    return true;
}

/* Get the piece at a given position on the board */
Piece* Board::getPieceFromCoordinate(Coordinate coord) {
    return this->squares[coord.row][coord.column].get();
}

/* Return true if the destination contains a piece of the same colour */
bool Board::isFriendlyPiece(Piece *movingPiece, Coordinate dest) {
    Piece *destinationPiece = this->getPieceFromCoordinate(dest); 
    
    if (destinationPiece == nullptr) {
        return false;
    }
    
    return (movingPiece->getColour() == destinationPiece->getColour());
}

/* Return true if the destination contains a piece of different colour */
bool Board::isEnemyPiece(Piece *movingPiece, Coordinate dest) {
    Piece *destinationPiece = this->getPieceFromCoordinate(dest); 
    
    if (destinationPiece == nullptr) {
        return false;
    }
    
    return (movingPiece->getColour() != destinationPiece->getColour());
}

/* Return true if there are no pieces between two coordinates */
bool Board::isPathClear(Coordinate start, Coordinate end) {
    if (start.row == end.row) {
        /* Left-to-right direction */
        if (start.column < end.column) {
            for (int i = start.column+1; i <= end.column-1; i++) {
                Coordinate pieceToCheck = {start.row, i};
                if (this->getPieceFromCoordinate(pieceToCheck) != nullptr) {
                    return false;
                }
            }
        }
        /* Right-to-left direction */
        else {
            for (int i = end.column+1; i >= start.column-1; i--) {
                Coordinate pieceToCheck = {start.row, i};
                if (this->getPieceFromCoordinate(pieceToCheck) != nullptr) {
                    return false;
                }
            }
        }
        return true;
    }

    if (start.column == end.column) {
        /* Top-to-bottom direction*/
        if (start.row < end.row) {
            for (int i = start.row+1; i <= end.row-1; i++) {
                Coordinate pieceToCheck = {i, start.column};
                if (this->getPieceFromCoordinate(pieceToCheck) != nullptr) {
                    return false;
                }
            }
        }
        /* Bottom-to-top direction */
        else {
            for (int i = start.row-1; i >= end.row+1; i--) {
                Coordinate pieceToCheck = {i, start.column};
                if (this->getPieceFromCoordinate(pieceToCheck) != nullptr) {
                    return false;
                }
            }
        }
        return true;
    }

    if (abs(start.row - end.row) == abs(start.column - end.column)) {
        int rowStep = (end.row > start.row) ? 1 : -1;
        int columnStep = (end.column > start.column) ? 1 : -1;

        int row = start.row + rowStep;
        int column = start.column + columnStep;

        while (row != end.row && column != end.column) {
            Coordinate pieceToCheck = {row, column};

            if (this->getPieceFromCoordinate(pieceToCheck) != nullptr) {
                return false;
            }
            row += rowStep;
            column += columnStep;
        }
        return true;
    }
    
    return false;
}