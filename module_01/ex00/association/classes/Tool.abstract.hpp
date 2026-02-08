#pragma once

#include "base_libs.hpp"
#include "./Worker.hpp"

#define NO_OWNER NULL

class Worker;

class Tool
{
    protected:
        int _number_of_uses;
        Worker* _owner; 

    public:
        Tool(): _number_of_uses(0), _owner(NO_OWNER) { std::cout << "Constructor Tool() called" << std::endl; }
        virtual ~Tool() { std::cout << "Destructor for Tool class called" << std::endl; }
        
        void giveTo(Worker* new_owner);
        
        void takeAwayFrom(Worker* worker);
        
        virtual void use() = 0;
};

