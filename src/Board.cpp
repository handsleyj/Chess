#include "../include/Board.h"
#include <iostream>

/* To create the chess board array */
Board::Board() {
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            squares[row][col] = '.';
        }
    }
}

/* To display the chess board to the screen */
void Board::display() {
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            std::cout << squares[row][col] << " ";
        }
        std::cout << "\n";
    }
}