#pragma once

#include <string>

struct Coordinate {
    int row;
    int column;
};

Coordinate toCoordinates(const std::string &square);