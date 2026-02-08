#pragma once

#include "base_libs.hpp"
#include "../structs/Position.hpp"
#include "../structs/Statistic.hpp"
#include "./Tool.abstract.hpp"

class Tool;

class Worker
{
    private:
        friend class Tool;
        std::vector<Tool*> _tools;

    public:
        Position _coordonnee;
        Statistic _stat;

        Worker() : _coordonnee(), _stat() 
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

        // Tool related methods
        void useTool(Tool* tool_to_use);
};