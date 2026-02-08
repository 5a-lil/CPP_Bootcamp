#pragma once

#include "base_libs.hpp"
#include "./Tool.abstract.hpp"

class Hammer: virtual public Tool
{
    public:
        Hammer(): Tool() { std::cout << "Constructor Hammer() called" << std::endl; }
        ~Hammer() { std::cout << "Destructor for Hammer class called" << std::endl; }
        
        void use() { this->_number_of_uses++; std::cout << "Hammer used by " << this->_owner << ", Hammer uses: " << this->_number_of_uses << std::endl; };
};

