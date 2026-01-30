#pragma once

#include "base_libs.hpp"
#include "../structs/Position.hpp"
#include "../structs/Statistic.hpp"
#include "../classes/Shovel.hpp"
#include "../classes/Hammer.hpp"

class Worker
{
    private:
        Tool* _Tool;

    public:
        Position _coordonnee;
        Statistic _stat;

        Worker() : _Tool(NULL), _coordonnee(), _stat() 
        { 
            std::cout << "Constructor Worker() called." << std::endl; 
        }

        Worker(Tool* Tool, Position coordonnee, Statistic stat) : 
                                                        _Tool(Tool),
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

        // Tool related methods
        void giveTool(Worker& worker) 
        {
            if (this->_Tool)
            {
                worker._Tool = this->_Tool;
                this->_Tool = NULL;
            }
            else
                std::cerr << "You could not give your Tool because you are a looser and you do not have one" << std::endl;
        }
        
        void getRidOfTool() 
        {
            if (this->_Tool)
                this->_Tool = NULL;
            else
                std::cerr << "You could not get rid of your Tool because you already not have one" << std::endl;
        }

        void useTool() 
        {
            if (this->_Tool)
                this->_Tool->use();
            else
                std::cerr << "No Tool is equiped to use" << std::endl;
        }
};