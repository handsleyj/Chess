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
    if(!this->isLegalMove(start, end)) {
        return false;
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
            for (int i = start.column-1; i >= end.column+1;  i--) {
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

/* Returns true if a pawn move is legal */
bool Board::isPawnMoveLegal(Piece *pawn, Coordinate start, Coordinate end) {
    int rowDiff = start.row - end.row;
    int columnDiff = abs(start.column - end.column);

    /* White pawns - move up the board*/
    if (pawn->getColour() == PieceColour::WHITE) {
        if (columnDiff == 0) {
            if (this->getPieceFromCoordinate(end) != nullptr) {
                return false;
            }

            /* Two-square move for pawns unmoved at start */
            if (rowDiff == 2) {
                if (!this->isPathClear(start, end)) {
                    return false;
                }
            }
            return true;
        }

        /* If move is diagonal, the move must be a take */
        return this->isEnemyPiece(pawn, end);
    }
    /* Black pawns - move down the board */
    else {
        if (columnDiff == 0) {
            if (this->getPieceFromCoordinate(end) != nullptr) {
                return false;
            }

            if (rowDiff == -2) {
                if(!this->isPathClear(start, end)) {
                    return false;
                }
            }
            return true;
        }
        return this->isEnemyPiece(pawn, end);
    }
}

bool Board::isInCheck(PieceColour colour) {
    Coordinate kingPosition = {-1, -1};

    /* Find the position of the king of the given colour */
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            Piece *pieceToCheck = this->getPieceFromCoordinate({row, col});
            
            /* Skip empty spaces */
            if (pieceToCheck == nullptr) {
                continue;
            }

            if ((pieceToCheck->getColour() == colour) && (pieceToCheck->getType() == PieceType::KING)) {
                kingPosition = {row, col};
                break;
            }
        }

        if (kingPosition.row != -1) {
            break;
        }
    }

    if (kingPosition.row == -1) {
        return false;
    }
    
    /* Determine if enemy pieces can attack the king in that position */
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            Piece *pieceToCheck = this->getPieceFromCoordinate({row, col});

            if (pieceToCheck == nullptr || pieceToCheck->getColour() == colour) {
                continue;
            }

            Coordinate piecePosition = {row, col};

            /* Pawn movement different from taking */
            if (pieceToCheck->getType() == PieceType::PAWN) {
                int rowDiff = piecePosition.row - kingPosition.row;
                int columnDiff = abs(piecePosition.column - kingPosition.column);

                if (columnDiff == 1) {
                    if (pieceToCheck->getColour() == PieceColour::WHITE && rowDiff == 1) {
                        return true;
                    }

                    if (pieceToCheck->getColour() == PieceColour::BLACK && rowDiff == -1) {
                        return true;
                    }
                }
                continue;
            }

            /* Check if piece can reach king*/
            if (!pieceToCheck->canMove(piecePosition, kingPosition)) {
                continue;
            }

            /* Rook, bishop, queen cannot jump over pieces */
            if (
                pieceToCheck->getType() == PieceType::ROOK ||
                pieceToCheck->getType() == PieceType::BISHOP || 
                pieceToCheck->getType() == PieceType::QUEEN
            ) {
                if (!this->isPathClear(piecePosition, kingPosition)) {
                    continue;
                }
            }
            return true;
        }
    }
    return false;
}

/* Returns true if a move is legal for a given piece */
bool Board::isLegalMove(Coordinate start, Coordinate end) {
    Piece *pieceToMove = this->getPieceFromCoordinate(start);

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

    if (pieceToMove->getType() == PieceType::PAWN) {
        if (!this->isPawnMoveLegal(pieceToMove, start, end)) {
            return false;
        }
    }

    if (this->wouldBeInCheck(start, end)) {
        return false;
    }

    return true;
}

/* Returns true if a move would put the current colour's king in check */
bool Board::wouldBeInCheck(Coordinate start, Coordinate end) {
    PieceColour currentColour = this->getPieceFromCoordinate(start)->getColour();
    std::unique_ptr<Piece> capturedPiece = std::move(this->squares[end.row][end.column]);
    
    /* Move piece temporarily */
    this->squares[end.row][end.column] = std::move(this->squares[start.row][start.column]);

    /* Check if current colour's king is in check */
    bool inCheck = this->isInCheck(currentColour);

    /* Undo move */
    this->squares[start.row][start.column] = std::move(this->squares[end.row][end.column]);

    this->squares[end.row][end.column] = std::move(capturedPiece);

    return inCheck;
}

/* Returns true if the given colour is in checkmate */
bool Board::isCheckmate(PieceColour colour) {
    if (!this->isInCheck(colour)) {
        return false;
    }

    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            Piece *pieceToCheck = this->getPieceFromCoordinate({row, col}); 
            
            if (pieceToCheck == nullptr) {
                continue;
            }

            if (pieceToCheck->getColour() != colour) {
                continue;
            }

            Coordinate start = {row, col};
            /* Check if there is a legal move for this piece */
            for (int endRow = 0; endRow < 8; endRow++) {
                for (int endCol = 0; endCol < 8; endCol++) {
                    Coordinate end = {endRow, endCol};

                    if (this->isLegalMove(start, end)) {
                        return false;
                    }
                }
            }
        }
    }
    /* If there are no legal moves remaining, and king is in check, they have been checkmated */
    return true;
}

/* Return true if in stalemate - not in check & no legal moves available */
bool Board::isStalemate(PieceColour colour) {
    if (this->isInCheck(colour)) {
        return false;
    }

    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            Piece *pieceToCheck = this->getPieceFromCoordinate({row, col});
            
            if (pieceToCheck == nullptr) {
                continue;
            }

            if (pieceToCheck->getColour() != colour) {
                continue;
            }

            Coordinate start = {row, col};
            for (int endRow = 0; endRow < 8; endRow++) {
                for (int endCol = 0; endCol < 8; endCol++) {
                    Coordinate end = {endRow, endCol};

                    if (this->isLegalMove(start, end)) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

/* -------------------------------------------------------------------- */

/* Remove all piece from the board. 
 * FOR TESTING PURPOSES ONLY 
*/
void Board::clearBoard() {
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            this->squares[row][col] = nullptr;
        }
    }
}

/* Place a piece and a given coordinate. 
 * FOR TESTING PURPOSES ONLY 
*/
void Board::placePiece(Coordinate position, PieceType type, PieceColour colour) {
    this->squares[position.row][position.column] = std::make_unique<Piece>(type, colour);
}

/* Force a piece to move without checking for move legality.
 * FOR TESTING PURPOSES ONLY 
*/
void Board::forceMovePiece(Coordinate start, Coordinate end) {
    this->squares[end.row][end.column] = std::move(this->squares[start.row][start.column]);
}