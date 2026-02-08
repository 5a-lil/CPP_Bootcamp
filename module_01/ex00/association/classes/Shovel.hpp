#pragma once

#include "base_libs.hpp"
#include "./Tool.abstract.hpp"

class Shovel: virtual public Tool
{
    public:
        Shovel(): Tool() { std::cout << "Constructor Shovel() called" << std::endl; }
        ~Shovel() { std::cout << "Destructor for Shovel class called" << std::endl; }
        
        void use() { this->_number_of_uses++; std::cout << "Shovel used by " << this->_owner << ", shovel uses: " << this->_number_of_uses << std::endl; };
};

