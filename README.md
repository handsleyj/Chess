# Chess Game

A chess game written in C++ and rendered using SFML graphics.

## Compilation

### Option 1 - compile with CMake:

1. Build the CMakeChess file.

2. Execute the built file by typing into the terminal:
    ```bash 
    .\build\bin\CMakeChess.exe 
    ```

### Option 2 - compile using GNU:

1. In the terminal, compile the executable:
    ```bash
    g++ src/*.cpp -Iinclude -o chessGame
    ```

2. Execute the compiled ```.exe``` file:
    ```bash
    ./chessGame
    ```

## Compile test files

The following files are for testing only

### Test Board class

1. In the terminal, compile the executable:
    ```bash
    g++ src/Board.cpp src/Piece.cpp src/Coordinate.cpp tests/test_board.cpp -o test_board
    ```

2. Execute the compiled ```.exe``` file:
    ```bash
    ./test_board
    ```

### Test Coordinate class

1. In the terminal, compile the executable:
    ```bash
    g++ src/Coordinate.cpp tests/test_coordinate.cpp -o test_coordinate
    ```

2. Execute the ```.exe``` file:
    ```bash
    ./test_coordinate
    ```

