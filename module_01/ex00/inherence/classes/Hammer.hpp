#pragma once

#include "base_libs.hpp"
#include "./Tool.abstract.hpp"

class Hammer: virtual public Tool
{
    public:
        Hammer(): Tool() { std::cout << "Constructor Hammer() called" << std::endl; }
        ~Hammer() { std::cout << "Destructor for Hammer class called" << std::endl; }
        void use() { this->Tool::_numberOfUses++; std::cout << "🔨 Hammer used, Hammer uses: " << this->Tool::_numberOfUses << std::endl; }
};