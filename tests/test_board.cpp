#include <cassert>
#include <iostream>

#include "../include/Board.h"
#include "../include/Coordinate.h"

void testPawnMovement();
void testRookMovement();
void testKnightMovement();
void testBishopMovement();
void testQueenMovement();
void testKingMovement();

int main() {
    std::cout << "Running Tests - Board...\n";

    testPawnMovement();
    testRookMovement();
    testKnightMovement();
    testBishopMovement();
    testQueenMovement();
    testKingMovement();

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

void testKnightMovement() {

    /* Knight can move in L-shape */
    {
        Board board;
        /* WHITE */
        assert(board.movePiece(
            toCoordinates("b2"),
            toCoordinates("b4")
        ));
        assert(board.movePiece(
            toCoordinates("b1"),
            toCoordinates("c3")
        ));
        assert(board.movePiece(
            toCoordinates("c3"),
            toCoordinates("e4")
        ));

        /* BLACK */
        assert(board.movePiece(
            toCoordinates("g7"),
            toCoordinates("g5")
        ));
        assert(board.movePiece(
            toCoordinates("g8"),
            toCoordinates("f6")
        ));
        assert(board.movePiece(
            toCoordinates("f6"),
            toCoordinates("d5")
        ));
    }

    /* Knight cannot move one square */
    {
        Board board;
        /* WHITE */
        assert(board.movePiece(
            toCoordinates("b2"),
            toCoordinates("b4")
        ));
        assert(!board.movePiece(
            toCoordinates("b1"),
            toCoordinates("b2")
        ));

        /* BLACK */
        assert(board.movePiece(
            toCoordinates("g7"),
            toCoordinates("g5")
        ));
        assert(!board.movePiece(
            toCoordinates("g8"),
            toCoordinates("g7")
        ));
    }

    /* Knight cannot move diagonally */
    {
        Board board;
        /* WHITE */
        assert(board.movePiece(
            toCoordinates("b2"),
            toCoordinates("b4")
        ));
        assert(board.movePiece(
            toCoordinates("b1"),
            toCoordinates("c3")
        ));
        assert(!board.movePiece(
            toCoordinates("c3"),
            toCoordinates("d4")
        ));

        /* BLACK */
        assert(board.movePiece(
            toCoordinates("g7"),
            toCoordinates("g5")
        ));
        assert(board.movePiece(
            toCoordinates("g8"),
            toCoordinates("f6")
        ));
        assert(!board.movePiece(
            toCoordinates("f6"),
            toCoordinates("g5")
        ));
    }

    /* Knight can jump over pieces */
    {
        Board board;
        /* WHITE */
        assert(board.movePiece(
            toCoordinates("b1"),
            toCoordinates("c3")
        ));

        /* BLACK */
        assert(board.movePiece(
            toCoordinates("g8"),
            toCoordinates("f6")
        ));
    }

    /* Knight can capture enemy pieces */
    {
        Board board;
        /* WHITE takes black */
        assert(board.movePiece(
            toCoordinates("c7"),
            toCoordinates("c5")
        ));
        assert(board.movePiece(
            toCoordinates("c5"),
            toCoordinates("c4")
        ));
        assert(board.movePiece(
            toCoordinates("c4"),
            toCoordinates("c3")
        ));
        assert(board.movePiece(
            toCoordinates("b1"),
            toCoordinates("c3")
        ));

        /* BLACK takes white */
        assert(board.movePiece(
            toCoordinates("f2"),
            toCoordinates("f4")
        ));
        assert(board.movePiece(
            toCoordinates("f4"),
            toCoordinates("f5")
        ));
        assert(board.movePiece(
            toCoordinates("f5"),
            toCoordinates("f6")
        ));
        assert(board.movePiece(
            toCoordinates("g8"),
            toCoordinates("f6")
        ));
    }

    /* Knight cannot take friendly piece */
    {
        Board board;
        /* WHITE */
        assert(board.movePiece(
            toCoordinates("a2"),
            toCoordinates("a3")
        ));
        assert(!board.movePiece(
            toCoordinates("b1"),
            toCoordinates("a3")
        ));

        /* BLACK */
        assert(board.movePiece(
            toCoordinates("h7"),
            toCoordinates("h6")
        ));
        assert(!board.movePiece(
            toCoordinates("g8"),
            toCoordinates("h6")
        ));
    }
}

void testBishopMovement() {

    /* Bishop can move diagonally */
    {
        Board board;
        assert(board.movePiece(
            toCoordinates("b2"),
            toCoordinates("b3")
        ));
        assert(board.movePiece(
            toCoordinates("c1"),
            toCoordinates("a3")
        ));
        assert(board.movePiece(
            toCoordinates("a3"),
            toCoordinates("b4")
        ));
        assert(board.movePiece(
            toCoordinates("b4"),
            toCoordinates("c3")
        ));
        assert(board.movePiece(
            toCoordinates("c3"),
            toCoordinates("b2")
        ));
    }

    /* Bishop cannot move vertically*/
    {
        Board board;
        /* WHITE */
        assert(board.movePiece(
            toCoordinates("c2"),
            toCoordinates("c3")
        ));
        assert(!board.movePiece(
            toCoordinates("c1"),
            toCoordinates("c2")
        ));

        /* BLACK */
        assert(board.movePiece(
            toCoordinates("f7"),
            toCoordinates("f6")
        ));
        assert(!board.movePiece(
            toCoordinates("f8"),
            toCoordinates("f7")
        ));
    }

    /* Bishop cannot move horizontally */
    {
        Board board;
        /* WHITE */
        assert(board.movePiece(
            toCoordinates("b2"),
            toCoordinates("b4")
        ));
        assert(board.movePiece(
            toCoordinates("c1"),
            toCoordinates("a3")
        ));
        assert(!board.movePiece(
            toCoordinates("a3"),
            toCoordinates("b3")
        ));

        /* BLACK */
        assert(board.movePiece(
            toCoordinates("g7"),
            toCoordinates("g5")
        ));
        assert(board.movePiece(
            toCoordinates("f8"),
            toCoordinates("h6")
        ));
        assert(!board.movePiece(
            toCoordinates("h6"),
            toCoordinates("g6")
        ));
    }

    /* Bishop cannot jump over pieces */
    {
        Board board;
        /* WHITE */
        assert(!board.movePiece(
            toCoordinates("c1"),
            toCoordinates("a3")
        ));

        /* BLACK */
        assert(!board.movePiece(
            toCoordinates("f8"),
            toCoordinates("h6")
        ));
    }

    /* Bishop can capture enemy pieces */
    {
        Board board;
        /* WHITE takes black */
        assert(board.movePiece(
            toCoordinates("d2"),
            toCoordinates("d4")
        ));
        assert(board.movePiece(
            toCoordinates("e7"),
            toCoordinates("e5")
        ));
        assert(board.movePiece(
            toCoordinates("e5"),
            toCoordinates("e4")
        ));
        assert(board.movePiece(
            toCoordinates("e4"),
            toCoordinates("e3")
        ));
        assert(board.movePiece(
            toCoordinates("c1"),
            toCoordinates("e3")
        ));

        /* BLACK takes white */
        assert(board.movePiece(
            toCoordinates("d4"),
            toCoordinates("d5")
        ));
        assert(board.movePiece(
            toCoordinates("d5"),
            toCoordinates("d6")
        ));
        assert(board.movePiece(
            toCoordinates("f8"),
            toCoordinates("d6")
        ));
    }

    /* Bishop cannot capture a friendly piece */
    {
        Board board;
        /* WHITE */
        assert(!board.movePiece(
            toCoordinates("c1"),
            toCoordinates("d2")
        ));

        /* BLACK */
        assert(!board.movePiece(
            toCoordinates("f8"),
            toCoordinates("g7")
        ));
    }
}

void testQueenMovement() {

    /* Queen can move vertically */
    {
        Board board;
        /* WHITE */
        assert(board.movePiece(
            toCoordinates("d2"),
            toCoordinates("d4")
        ));
        assert(board.movePiece(
            toCoordinates("d1"),
            toCoordinates("d3")
        ));

        /* BLACK */
        assert(board.movePiece(
            toCoordinates("d7"),
            toCoordinates("d5")
        ));
        assert(board.movePiece(
            toCoordinates("d8"),
            toCoordinates("d6")
        ));
    }

    /* Queen can move horizontally */
    {
        Board board;
        /* WHITE */
        assert(board.movePiece(
            toCoordinates("d2"),
            toCoordinates("d4")
        ));
        assert(board.movePiece(
            toCoordinates("d1"),
            toCoordinates("d3")
        ));
        assert(board.movePiece(
            toCoordinates("d3"),
            toCoordinates("b3")
        ));

        /* BLACK */
        assert(board.movePiece(
            toCoordinates("d7"),
            toCoordinates("d5")
        ));
        assert(board.movePiece(
            toCoordinates("d8"),
            toCoordinates("d6")
        ));
        assert(board.movePiece(
            toCoordinates("d6"),
            toCoordinates("f6")
        ));
    }

    /* Queen can move diagonally */
    {
        Board board;
        /* WHITE */
        assert(board.movePiece(
            toCoordinates("e2"),
            toCoordinates("e4")
        ));
        assert(board.movePiece(
            toCoordinates("d1"),
            toCoordinates("f3")
        ));

        /* BLACK */
        assert(board.movePiece(
            toCoordinates("e7"),
            toCoordinates("e5")
        ));
        assert(board.movePiece(
            toCoordinates("d8"),
            toCoordinates("f6")
        ));
    }

    /* Queen cannot jump over pieces */
    {
        Board board;
        /* WHITE */
        assert(!board.movePiece(
            toCoordinates("d1"),
            toCoordinates("f3")
        ));

        /* BLACK */
        assert(!board.movePiece(
            toCoordinates("d8"),
            toCoordinates("f6")
        ));
    }

    /* Queen can capture enemy pieces */
    {
        Board board;
        /* WHITE takes black */
        assert(board.movePiece(
            toCoordinates("f7"),
            toCoordinates("f5")
        ));
        assert(board.movePiece(
            toCoordinates("f5"),
            toCoordinates("f4")
        ));
        assert(board.movePiece(
            toCoordinates("f4"),
            toCoordinates("f3")
        ));
        assert(board.movePiece(
            toCoordinates("f3"),
            toCoordinates("e2")
        ));
        assert(board.movePiece(
            toCoordinates("d1"),
            toCoordinates("e2")
        ));

        /* BLACK takes white */
        assert(board.movePiece(
            toCoordinates("e2"),
            toCoordinates("e4")
        ));
        assert(board.movePiece(
            toCoordinates("e4"),
            toCoordinates("e5")
        ));
        assert(board.movePiece(
            toCoordinates("e5"),
            toCoordinates("e6")
        ));
        assert(board.movePiece(
            toCoordinates("e6"),
            toCoordinates("d7")
        ));
        assert(board.movePiece(
            toCoordinates("d8"),
            toCoordinates("d7")
        ));
    }

    /* Queen cannot capture a friendly piece */
    {
        Board board;
        /* WHITE */
        assert(!board.movePiece(
            toCoordinates("d1"),
            toCoordinates("d2")
        ));

        /* BLACK */
        assert(!board.movePiece(
            toCoordinates("d8"),
            toCoordinates("d7")
        ));
    }
}

void testKingMovement() {

    /* King can move maximum of one square vertically */
    {
        Board board;
        /* WHITE */
        assert(board.movePiece(
            toCoordinates("e2"),
            toCoordinates("e4")
        ));
        assert(!board.movePiece(
            toCoordinates("e1"),
            toCoordinates("e3")
        ));
        assert(board.movePiece(
            toCoordinates("e1"),
            toCoordinates("e2")
        ));

        /* BLACK */
        assert(board.movePiece(
            toCoordinates("e7"),
            toCoordinates("e5")
        ));
        assert(!board.movePiece(
            toCoordinates("e8"),
            toCoordinates("e6")
        ));
        assert(board.movePiece(
            toCoordinates("e8"),
            toCoordinates("e7")
        ));
    }

    /* King can move maximum of one square horizontally */
    {
        Board board;
        /* WHITE */
        assert(board.movePiece(
            toCoordinates("e2"),
            toCoordinates("e4")
        ));
        assert(board.movePiece(
            toCoordinates("e1"),
            toCoordinates("e2")
        ));
        assert(board.movePiece(
            toCoordinates("e2"),
            toCoordinates("e3")
        ));
        assert(!board.movePiece(
            toCoordinates("e3"),
            toCoordinates("c3")
        ));
        assert(board.movePiece(
            toCoordinates("e3"),
            toCoordinates("d3")
        ));

        /* BLACK */
        assert(board.movePiece(
            toCoordinates("e7"),
            toCoordinates("e5")
        ));
        assert(board.movePiece(
            toCoordinates("e8"),
            toCoordinates("e7")
        ));
        assert(board.movePiece(
            toCoordinates("e7"),
            toCoordinates("e6")
        ));
        assert(!board.movePiece(
            toCoordinates("e6"),
            toCoordinates("c6")
        ));
        assert(board.movePiece(
            toCoordinates("e6"),
            toCoordinates("d6")
        ));
    }

    /* King can move maximum of one square diagonally */
    {
        Board board;
        /* WHITE */
        assert(board.movePiece(
            toCoordinates("d2"),
            toCoordinates("d4")
        ));
        assert(!board.movePiece(
            toCoordinates("e1"),
            toCoordinates("c3")
        ));
        assert(board.movePiece(
            toCoordinates("e1"),
            toCoordinates("d2")
        ));

        /* BLACK */
        assert(board.movePiece(
            toCoordinates("d7"),
            toCoordinates("d5")
        ));
        assert(!board.movePiece(
            toCoordinates("d8"),
            toCoordinates("c6")
        ));
        assert(board.movePiece(
            toCoordinates("d8"),
            toCoordinates("d7")
        ));
    }

    /* King can capture enemy piece */
    {
        Board board;
        /* WHITE takes black */
        assert(board.movePiece(
            toCoordinates("d7"),
            toCoordinates("d5")
        ));
        assert(board.movePiece(
            toCoordinates("d5"),
            toCoordinates("d4")
        ));
        assert(board.movePiece(
            toCoordinates("d4"),
            toCoordinates("d3")
        ));
        assert(board.movePiece(
            toCoordinates("d3"),
            toCoordinates("e2")
        ));
        assert(board.movePiece(
            toCoordinates("e1"),
            toCoordinates("e2")
        ));

        /* BLACK takes white */
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
            toCoordinates("g6"),
            toCoordinates("f7")
        ));
        assert(board.movePiece(
            toCoordinates("e8"),
            toCoordinates("f7")
        ));
    }

    /* King cannot capture a friendly piece */
    {
        Board board;
        /* WHITE */
        assert(!board.movePiece(
            toCoordinates("e1"),
            toCoordinates("e2")
        ));

        /* BLACK */
        assert(!board.movePiece(
            toCoordinates("e8"),
            toCoordinates("e7")
        ));
    }
}