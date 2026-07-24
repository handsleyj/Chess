#include "../include/Game.h"
#include "../include/Coordinate.h"
#include <iostream>

Game::Game() {
    this->currentTurn = Turn::WHITE;
}

/* Run the main gameplay loop */
void Game::run() {
    while (true) {
        board.display();
        std::string from, to;
        
        /* Get input */
        std::cout << ">> Enter Move (" << ((this->currentTurn == Turn::WHITE) ? "WHITE" : "BLACK") << "): ";
        std::cin >> from >> to;

        Coordinate start = toCoordinates(from);
        Coordinate end = toCoordinates(to);

        if (start.row == -1 || end.row == -1) {
            std::cout << "Invalid move format.\n";
            continue;
        }

        Piece *piece = board.getPieceFromCoordinate(start);

        /* Check if the piece exists */
        if (piece == nullptr) {
            std::cout << "No piece on that square.\n";
            continue;
        }

        /* Check if selected piece belongs to current player */
        if ((piece->getColour() == PieceColour::WHITE && this->currentTurn != Turn::WHITE) || 
            (piece->getColour() == PieceColour::BLACK && this->currentTurn != Turn::BLACK)) 
        {
            std::cout << "You cannot move that piece - it is the wrong colour.";
            continue;
        }

        /* Attempt to move the piece */
        if (!board.movePiece(start, end)) {
            std::cout << "Invalid move.\n";
            continue;
        }

        this->changeTurn();
    }
}

Turn Game::getCurrentTurn() {
    return this->currentTurn;
}

/* Flip the turn to the opposite player */
void Game::changeTurn() {
    this->currentTurn = (this->currentTurn == Turn::WHITE) ? Turn::BLACK : Turn::WHITE;
}