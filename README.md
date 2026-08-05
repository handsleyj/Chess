# Chess Game

A chess game written in C++.

## Compilation

To compile the program from the terminal, run:

```bash
g++ src/*.cpp -Iinclude -o chessGame
```

```bash
./chessGame
```

## Compile test files

The following files are for testing only

### Test Board class

To compile from terminal, run:
```bash
g++ src/Board.cpp src/Piece.cpp src/Coordinate.cpp tests/test_board.cpp -o test_board
```

```bash
./test_board
```

### Test Coordinate class

To compile from terminal, run:
```bash
g++ src/Coordinate.cpp tests/test_coordinate.cpp -o test_coordinate
```

```bash
./test_coordinate
```