#pragma once

#include "base_libs.hpp"
#include "./Worker.hpp"

#define NO_OWNER nullptr

class Worker;

class Tool
{
    protected:
        int _number_of_uses;
        Worker* _owner;

    public:
        Tool(): _number_of_uses(0), _owner(NO_OWNER) { std::cout << "Constructor Tool() called" << std::endl; }
        ~Tool() { std::cout << "Destructor for Tool class called" << std::endl; }

        Worker* getOwner()
        {
            return this->_owner;
        }

        void setOwner(Worker* owner)
        {
            this->_owner = owner;
        }

        virtual void use() = 0;
};