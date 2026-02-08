#pragma once

#include "base_libs.hpp"
#include "./Worker.hpp"

class Worker;

class Workshop
{
    private:
        std::vector<Worker*> _workers;

    public:
        Workshop() {};
        ~Workshop() {};

        void manageWorkers(Worker* worker, std::string cmd)
        {
            std::vector<Worker*>::iterator find_stash = std::find(this->_workers.begin(), this->_workers.end(), worker);
            if (cmd == "register")
                if (find_stash == this->_workers.end())
                {
                    std::cout << worker << " has been registered to workshop" << std::endl;
                    this->_workers.push_back(worker);
                }
                else
                    std::cerr << "Worker is already registered" << std::endl;
            else if (cmd == "release")
                if (find_stash == this->_workers.end())
                {
                    std::cerr << "Worker is not even register to release" << std::endl;
                    return;
                }
                else
                {
                    std::cout << worker << " was released from workshop" << std::endl;
                    this->_workers.erase(find_stash);
                }
            else
                std::cerr << "Command " << cmd << " is unknown" << std::endl;
        }

        void executeWorkDay();
};