#include "../include/Coordinate.h"
#include <cctype>

/* Converts input to coordinate values */
Coordinate toCoordinates(const std::string &square) {
    if (square.length() != 2) {
        return {-1, -1};
    }
    
    int col = std::tolower(square[0]) - 'a'; // character offset from 'a'
    int row = 8 - (square[1] - '0'); // character offset from '0' (top of the board, row 8)

    /* 
     * Ensure column does not exceed 'h' (7) or go below 'a' (0) 
     * Ensure row does not exceed 7 or go below 0
     */
    if ( col < 0 || col > 7 || row < 0 || row > 7 ) {
        return {-1, -1};
    }

    return {row, col};

}