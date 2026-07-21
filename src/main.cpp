#include "../include/Board.h"
#include <iostream>

int main() {
    Board board;

    board.display();

    board.movePiece(6, 0, 4, 2);

    std::cout << "\nAfter move:\n";

    board.display();

    return 0;
}