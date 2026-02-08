#include "Workshop.hpp"

void Workshop::executeWorkDay()
{
    std::cout << "WORK DAY:" << std::endl;
    std::vector<Worker*>::iterator beg = this->_workers.begin();
    std::vector<Worker*>::iterator end = this->_workers.end();
    for (std::vector<Worker*>::iterator it = beg; it < end; it++)
        (*it)->work();
}