#include "../include/Board.h"
#include <iostream>
#include <vector>
#include <memory>

/* Get the symbol to show for a given chess piece */
char getSymbol(Piece &piece) {
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
    std::vector<PieceType> edgeRow {
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
    for (int row = 0; row < 8; row++) {
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
}

void Board::movePiece(int startRow, int startCol, int endRow, int endCol) {
    squares[endRow][endCol] = std::move(squares[startRow][startCol]);
}
