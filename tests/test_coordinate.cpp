#include <cassert>
#include <iostream>

#include "../include/Coordinate.h"

void testValidCoordinates();
void testInvalidCoordinates();

int main() {
    std::cout << "Running Tests - Coordinate...\n";

    testValidCoordinates();
    testInvalidCoordinates();

    std::cout << "All tests passed\n";

    return 0;
}

void testValidCoordinates() {
    Coordinate c = toCoordinates("a1");
    assert(c.row == 7);
    assert(c.column == 0);

    c = toCoordinates("h8");
    assert(c.row == 0);
    assert(c.column == 7);

    c = toCoordinates("e4");
    assert(c.row == 4);
    assert(c.column == 4);

    c = toCoordinates("c6");
    assert(c.row == 2);
    assert(c.column == 2);

    c = toCoordinates("A2");
    assert(c.row == 6);
    assert(c.column == 0);
}

void testInvalidCoordinates() {
    Coordinate c = toCoordinates("i1");
    assert(c.row == -1);
    assert(c.column == -1);

    c = toCoordinates("a9");
    assert(c.row == -1);
    assert(c.column == -1);

    c = toCoordinates("z5");
    assert(c.row == -1);
    assert(c.column == -1);

    assert(toCoordinates("").row == -1);
    assert(toCoordinates("a").row == -1);
    assert(toCoordinates("11").row == -1);
    assert(toCoordinates("aa").row == -1);
    assert(toCoordinates("a10").row == -1);
    assert(toCoordinates("1a").row == -1);
}