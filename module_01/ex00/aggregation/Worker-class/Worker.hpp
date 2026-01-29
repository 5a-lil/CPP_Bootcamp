#pragma once

#include "base_libs.hpp"
#include "../structs/Position.hpp"
#include "../structs/Statistic.hpp"
#include "../structs/Shovel.hpp"

class Worker
{
    private:
        Shovel* _shovel;

    public:
        Position _coordonnee;
        Statistic _stat;

        Worker() : _shovel(NULL), _coordonnee(), _stat() 
        { 
            std::cout << "Constructor Worker() called." << std::endl; 
        }

        Worker(Shovel* shovel, Position coordonnee, Statistic stat) : 
                                                        _shovel(shovel),
                                                        _coordonnee(coordonnee._x, coordonnee._y, coordonnee._z),
                                                        _stat(stat._level, stat._exp)
        { 
            std::cout << "Constructor Worker(Position coordonnee, Statistic stat) called." << std::endl; 
        }

        ~Worker() 
        { 
            std::cout << "Destructor ~Worker() called." << std::endl; 
        }

        void dataLog() 
        { 
            std::cout << "Worker object data log:" << std::endl; 
            this->_coordonnee.dataLog(); 
            this->_stat.dataLog(); }

        // Shovel related methods
        void giveShovel(Worker& worker) 
        {
            if (this->_shovel)
            {
                worker._shovel = this->_shovel;
                this->_shovel = NULL;
            }
            else
                std::cerr << "You could not give your Shovel because you are a looser and you do not have one" << std::endl;
        }
        
        void getRidOfShovel() 
        {
            if (this->_shovel)
                this->_shovel = NULL;
            else
                std::cerr << "You could not get rid of your Shovel because you already not have one" << std::endl;
        }

        void useShovel() 
        {
            if (this->_shovel)
                this->_shovel->use();
            else
                std::cerr << "No Shovel is equiped to use" << std::endl;
        }
};