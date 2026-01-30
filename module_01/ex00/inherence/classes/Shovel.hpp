#pragma once

#include "base_libs.hpp"
#include "./Tool.abstract.hpp"

class Shovel: virtual public Tool
{
    public:
        Shovel(): Tool() { std::cout << "Constructor Shovel() called" << std::endl; }
        ~Shovel() { std::cout << "Destructor for Shovel class called" << std::endl; }
        void use() { this->Tool::_numberOfUses++; std::cout << "🪏 Shovel used, shovel uses: " << this->Tool::_numberOfUses << std::endl; }
};