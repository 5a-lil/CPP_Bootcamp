#pragma once

#include "base_libs.hpp"

struct Statistic
{
    int _level, _exp;

    Statistic() : _level(1), _exp(0) { std::cout << "Constructor Statistic() called." << std::endl; }
    Statistic(int level, int exp) : _level(level), _exp(exp) { std::cout << "Constructor Statistic(int level, int exp) called." << std::endl; }
    ~Statistic() { std::cout << "Destructor ~Statistic() called." << std::endl; }

    void dataLog() { std::cout << "Statistic object data log: _level=" << this->_level << " _exp=" << this->_exp << std::endl; }
};