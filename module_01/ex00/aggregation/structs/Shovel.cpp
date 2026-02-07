#include "Shovel.hpp"

void Shovel::giveTo(Worker* new_owner)
{
    if (new_owner->_shovel != nullptr)
    {
        std::cerr << "error: you already have a shovel equiped" << std::endl;
        return;
    }
    if (this->_owner != NO_OWNER)
        this->_owner->_shovel = nullptr;
    this->_owner = new_owner;
    this->_owner->_shovel = this;
    std::cout << "new shovel owner: " << this->_owner << std::endl;
}
    
    void Shovel::takeAwayFrom(Worker* worker)
    {
        if (worker->_shovel != this)
        {
            std::cerr << "error: you dont have this weapon equiped" << std::endl;
            return;
        }
        this->_owner->_shovel = nullptr;
        this->_owner = nullptr;
    }