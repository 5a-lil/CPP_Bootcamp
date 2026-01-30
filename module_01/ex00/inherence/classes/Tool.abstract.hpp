#pragma once

#include "base_libs.hpp"

class Tool
{
    protected:
        int _numberOfUses;

    public:
        Tool(): _numberOfUses(0) { std::cout << "Constructor Tool() called" << std::endl; }
        virtual ~Tool() { std::cout << "Destructor for Tool abstract class called" << std::endl; }
        virtual void use() = 0;
};