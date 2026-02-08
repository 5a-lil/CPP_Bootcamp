#pragma once

#include "base_libs.hpp"
#include "../structs/Position.hpp"
#include "../structs/Statistic.hpp"
#include "../structs/Shovel.hpp"

struct Shovel;

class Worker
{
    private:
        friend struct Shovel;
        Shovel* _shovel;

    public:
        Position _coordonnee;
        Statistic _stat;

        Worker() : _shovel(NULL), _coordonnee(), _stat() 
        { 
            std::cout << "Constructor Worker() called." << std::endl;
        }

        ~Worker() 
        { 
            std::cout << "Destructor ~Worker() called." << std::endl;
        }

        void dataLog() 
        { 
            std::cout << "Worker object data log:" << std::endl; 
            this->_coordonnee.dataLog(); 
            this->_stat.dataLog(); 
        }

        // Shovel related methods
        void useShovel();
};