#pragma once

#include "base_libs.hpp"

struct Position
{
    int _x, _y, _z;

    Position() : _x(0), _y(0), _z(0) { std::cout << "Constructor Position() called." << std::endl; }
    Position(int x, int y, int z) : _x(x), _y(y), _z(z) { std::cout << "Constructor Position(int x, int y, int z) called." << std::endl; }
    ~Position() { std::cout << "Destructor ~Position() called." << std::endl; }

    void dataLog() { std::cout << "Position object data log: x=" << this->_x << " y=" << this->_y << " z=" << this->_z << std::endl; }
};