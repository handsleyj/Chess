#include "../include/Board.h"
#include <iostream>
#include <cstring>
#include <cctype>

struct Coordinate {
    int row;
    int column;
};

/* Converts input to coordinate values */
Coordinate toCoordinates(const char *str_ptr) {
    if (std::strlen(str_ptr) != 2) {
        return {-1, -1};
    }
    
    int col = std::tolower(str_ptr[0]) - 'a'; // character offset from 'a'
    int row = 8 - (str_ptr[1] - '0'); // character offset from '0' (top of the board, row 8)

    /* 
     * Ensure column does not exceed 'h' (7) or go below 'a' (0) 
     * Ensure row does not exceed 7 or go below 0
     */
    if ( col < 0 || col > 7 || row < 0 || row > 7 ) {
        return {-1, -1};
    }

    return {row, col};

}

int main() {
    Board board;

    board.display();

    /* Test (row, col) conversion */
    Coordinate start = toCoordinates("e2");
    Coordinate end = toCoordinates("e4");
    
    board.movePiece(
        start.row, start.column, 
        end.row, end.column
    );

    std::cout << "\nAfter move:\n";

    board.display();

    return 0;
}