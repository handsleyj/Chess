#include "../include/Game.h"
#include "../include/Coordinate.h"
#include <iostream>

Game::Game() {}

void Game::run() {
    while (true) {
        board.display();
        std::string from, to;
        
        /* Get input */
        std::cout << ">> Enter Move: ";
        std::cin >> from >> to;

        Coordinate start = toCoordinates(from);
        Coordinate end = toCoordinates(to);

        if (start.row == -1 || end.row == -1) {
            std::cout << "Invalid move format.\n";
        }
        else {
            if (!board.movePiece(start, end)) {
                std::cout << "No piece on that square!\n";
                continue;
            }
        }
    }
}