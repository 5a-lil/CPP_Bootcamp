#pragma once

#include "base_libs.hpp"
#include "../Worker-class/Worker.hpp"

#define NO_OWNER nullptr

class Worker;

struct Shovel
{
    private:
        int _number_of_uses;
        Worker* _owner; 

    public:
    Shovel(): _number_of_uses(0), _owner(NO_OWNER) { std::cout << "Constructor Shovel() called" << std::endl; }
    ~Shovel() { std::cout << "Destructor for Shovel class called" << std::endl; }
    
    void giveTo(Worker* new_owner);
    
    void takeAwayFrom(Worker* worker);
    
    void use() { this->_number_of_uses++; std::cout << "Shovel used by " << this->_owner << ", shovel uses: " << this->_number_of_uses << std::endl; }
};

