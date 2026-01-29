#pragma once

#include "base_libs.hpp"

struct Shovel
{
    int _numberOfUses;

    Shovel(): _numberOfUses(0) { std::cout << "Constructor Shovel() called" << std::endl; }
    ~Shovel() { std::cout << "Destructor for Shovel class called" << std::endl; }

    void use() { this->_numberOfUses++; std::cout << "Shovel used, shovel uses: " << this->_numberOfUses << std::endl; }
};