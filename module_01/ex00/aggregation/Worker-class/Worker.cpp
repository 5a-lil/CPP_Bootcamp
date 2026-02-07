#include "Worker.hpp"

void Worker::useShovel() 
{
    if (this->_shovel)
        this->_shovel->use();
    else
        std::cerr << "No Shovel is equiped to use" << std::endl;
}