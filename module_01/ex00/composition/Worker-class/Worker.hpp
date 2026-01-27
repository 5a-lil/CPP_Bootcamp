#pragma once

#include "base_libs.hpp"
#include "../Position-struct/Position.hpp"
#include "../Statistic-struct/Statistic.hpp"

class Worker
{
    public:
        Position _coordonnee;
        Statistic _stat;

        Worker() : _coordonnee(), _stat() { std::cout << "Constructor Worker() called." << std::endl; }
        Worker(Position coordonnee, Statistic stat) : _coordonnee(coordonnee._x, coordonnee._y, coordonnee._z),
                                                      _stat(stat._level, stat._exp)
                                                    { std::cout << "Constructor Worker(Position coordonnee, Statistic stat) called." << std::endl; }
        ~Worker() { std::cout << "Destructor ~Worker() called." << std::endl; }

        void dataLog() { std::cout << "Worker object data log:" << std::endl; this->_coordonnee.dataLog(); this->_stat.dataLog(); }
};