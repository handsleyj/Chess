#include <cassert>
#include <iostream>

#include "../include/Board.h"
#include "../include/Coordinate.h"

void testPawnMovement();
/* TODO */
// void testRookMovement();
// void testKnightMovement();
// void testBishopMovement();
// void testQueenMovement();
// void testKingMovement();

int main() {
    std::cout << "Running Tests - Board...\n";

    testPawnMovement();
    /* TODO */
    // testRookMovement();
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