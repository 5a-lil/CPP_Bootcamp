#pragma once

#include "base_libs.hpp"
#include "../structs/Position.hpp"
#include "../structs/Statistic.hpp"
#include "./Shovel.hpp"

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
        void equipShovel(Shovel* shovel_to_equip)
        {
            if (this->_shovel)
                std::cerr << "equipShovel(): you already have a shovel equiped" << std::endl;
            else
            {
                if (shovel_to_equip->getOwner() != NO_OWNER)
                    shovel_to_equip->getOwner()->unequipShovel();
                this->_shovel = shovel_to_equip;
                shovel_to_equip->_owner = this;
            }
        }

        void unequipShovel()
        {
            if (this->_shovel)
            {
                this->_shovel->getOwner() = NO_OWNER;
                this->_shovel = nullptr;
            }
            else
                std::cerr << "unequipShovel(): you have no shovel equiped" << std::endl;   
        }

        void useShovel() 
        {
            if (this->_shovel)
                this->_shovel->use();
            else
                std::cerr << "No Shovel is equiped to use" << std::endl;
        }
};