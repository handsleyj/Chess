#include <cassert>
#include <iostream>

#include "../include/Board.h"
#include "../include/Coordinate.h"

void testPawnMovement();
void testRookMovement();
/* TODO */
// void testKnightMovement();
// void testBishopMovement();
// void testQueenMovement();
// void testKingMovement();

int main() {
    std::cout << "Running Tests - Board...\n";

    testPawnMovement();
    testRookMovement();
    /* TODO */
    // testKnightMovement();
    // testBishopMovement();
    // testQueenMovement();
    // testKingMovement();

    std::cout << "All tests passed\n";

    return 0;
}

void testPawnMovement() {
    
    /* Pawn can move one square */
    {
        Board board;
        /* WHITE */
        assert(board.movePiece(
            toCoordinates("a2"), 
            toCoordinates("a3")
        ));

        /* BLACK */
        assert(board.movePiece(
            toCoordinates("a7"),
            toCoordinates("a6")
        ));
    }   

    /* Pawn can move two squares on first go */
    {
        Board board;
        /* WHITE */
        assert(board.movePiece(
            toCoordinates("a2"), 
            toCoordinates("a4")
        ));

        /* BLACK */
        assert(board.movePiece(
            toCoordinates("a7"),
            toCoordinates("a5")
        ));
    }

    /* Pawn cannot move more than two spaces forward */
    {
        Board board;
        /* WHITE */
        assert(!board.movePiece(
            toCoordinates("a2"),
            toCoordinates("a5")
        ));
        
        /* BLACK */
        assert(!board.movePiece(
            toCoordinates("a7"),
            toCoordinates("a4")
        ));
    }

    /* Pawn cannot move backwards */
    {
        Board board;
        /* WHITE */
        assert(!board.movePiece(
            toCoordinates("a2"),
            toCoordinates("a1")
        ));
        
        /* BLACK */
        assert(!board.movePiece(
            toCoordinates("a7"),
            toCoordinates("a8")
        ));
    }

    /* Pawn cannot move sideways */
    {
        Board board;
        /* WHITE */
        assert(!board.movePiece(
            toCoordinates("a2"),
            toCoordinates("b2")
        ));
        
        /* BLACK */
        assert(!board.movePiece(
            toCoordinates("a7"),
            toCoordinates("b7")
        ));
    }

    /* Pawn cannot move two squares after first move */
    {
        Board board;
        /* WHITE */
        assert(board.movePiece(
            toCoordinates("a2"),
            toCoordinates("a4")
        ));
        assert(!board.movePiece(
            toCoordinates("a4"),
            toCoordinates("a6")
        ));

        /* BLACK */
        assert(board.movePiece(
            toCoordinates("b7"),
            toCoordinates("b5")
        ));
        assert(!board.movePiece(
            toCoordinates("b5"),
            toCoordinates("b3")
        ));
    }

    /* Pawn cannot capture diagnonally onto an empty space */
    {
        Board board;
        /* WHITE */
        assert(!board.movePiece(
            toCoordinates("a2"),
            toCoordinates("b3")
        ));

        /* BLACK */
        assert(!board.movePiece(
            toCoordinates("a7"),
            toCoordinates("b6")
        ));
    }

    /* Pawn can capture diagonally */
    {
        Board board;
        
        /* WHITE takes black*/
        assert(board.movePiece(
            toCoordinates("a2"),
            toCoordinates("a4")
        ));
        assert(board.movePiece(
            toCoordinates("b7"),
            toCoordinates("b5")
        ));
        assert(board.movePiece(
            toCoordinates("a4"),
            toCoordinates("b5")
        ));

        /* BLACK takes white */
        assert(board.movePiece(
            toCoordinates("d7"),
            toCoordinates("d5")
        ));
        assert(board.movePiece(
            toCoordinates("c2"),
            toCoordinates("c4")
        ));
        assert(board.movePiece(
            toCoordinates("d5"),
            toCoordinates("c4")
        ));
    }
}

void testRookMovement() {
    
    /* Rook can move vertically when path is clear */
    {
        Board board;
        /* WHITE */
        assert(board.movePiece(
            toCoordinates("a2"),
            toCoordinates("a4")
        ));
        assert(board.movePiece(
            toCoordinates("a1"),
            toCoordinates("a3")
        ));

        /* BLACK */
        assert(board.movePiece(
            toCoordinates("h7"),
            toCoordinates("h5")
        ));
        assert(board.movePiece(
            toCoordinates("h8"),
            toCoordinates("h6")
        ));
    }

    /* Rook can move horizontally when path is clear */
    {
        Board board;
        /* WHITE */
        assert(board.movePiece(
            toCoordinates("a2"),
            toCoordinates("a4")
        ));
        assert(board.movePiece(
            toCoordinates("a1"),
            toCoordinates("a3")
        ));
        assert(board.movePiece(
            toCoordinates("a3"),
            toCoordinates("h3")
        ));

        /* BLACK */
        assert(board.movePiece(
            toCoordinates("h7"),
            toCoordinates("h5")
        ));
        assert(board.movePiece(
            toCoordinates("h8"),
            toCoordinates("h6")
        ));
        assert(board.movePiece(
            toCoordinates("h6"),
            toCoordinates("a6")
        ));
    }

    /* Rook cannot move diagonally when path is clear */
    {
        Board board;
        /* WHITE */
        assert(board.movePiece(
            toCoordinates("a2"),
            toCoordinates("a4")
        ));
        assert(board.movePiece(
            toCoordinates("a1"),
            toCoordinates("a2")
        ));
        assert(!board.movePiece(
            toCoordinates("a2"),
            toCoordinates("d5")
        ));

        /* BLACK */
        assert(board.movePiece(
            toCoordinates("h7"),
            toCoordinates("h5")
        ));
        assert(board.movePiece(
            toCoordinates("h8"),
            toCoordinates("h7")
        ));
        assert(!board.movePiece(
            toCoordinates("h7"),
            toCoordinates("e4")
        ));
    }

    /* Rook cannot jump over pieces */
    {
        Board board;
        /* WHITE */
        assert(board.movePiece(
            toCoordinates("a2"),
            toCoordinates("a4")
        ));
        assert(!board.movePiece(
            toCoordinates("a1"),
            toCoordinates("a5")
        ));

        /* BLACK */
        assert(board.movePiece(
            toCoordinates("h7"),
            toCoordinates("h5")
        ));
        assert(!board.movePiece(
            toCoordinates("h8"),
            toCoordinates("h4")
        ));
    }

    /* Rook can capture another piece */
    {
        Board board;
        /* WHITE takes black */
        assert(board.movePiece(
            toCoordinates("a2"),
            toCoordinates("a4")
        ));
        assert(board.movePiece(
            toCoordinates("a1"),
            toCoordinates("a3")
        ));
        assert(board.movePiece(
            toCoordinates("b7"),
            toCoordinates("b5")
        ));
        assert(board.movePiece(
            toCoordinates("b5"),
            toCoordinates("b4")
        ));
        assert(board.movePiece(
            toCoordinates("b4"),
            toCoordinates("b3")
        ));
        assert(board.movePiece(
            toCoordinates("a3"),
            toCoordinates("b3")
        ));
        
        /* BLACK takes white */
        assert(board.movePiece(
            toCoordinates("h7"),
            toCoordinates("h5")
        ));
        assert(board.movePiece(
            toCoordinates("h8"),
            toCoordinates("h6")
        ));
        assert(board.movePiece(
            toCoordinates("g2"),
            toCoordinates("g4")
        ));
        assert(board.movePiece(
            toCoordinates("g4"),
            toCoordinates("g5")
        ));
        assert(board.movePiece(
            toCoordinates("g5"),
            toCoordinates("g6")
        ));
        assert(board.movePiece(
            toCoordinates("h6"),
            toCoordinates("g6")
        ));
    }

    /* Rook cannot capture friendly piece */
    {
        Board board;
        /* WHITE */
        assert(!board.movePiece(
            toCoordinates("a1"),
            toCoordinates("b1")
        ));

        /* BLACK */
        assert(!board.movePiece(
            toCoordinates("a8"),
            toCoordinates("a7")
        ));
    }
}