#include "Tool.abstract.hpp"

#define THIS_TOOL_HAS_AN_OWNER this->_owner != NO_OWNER

void Tool::giveTo(Worker* new_owner)
{
    std::vector<Tool*>::iterator find_stash = std::find(new_owner->_tools.begin(), new_owner->_tools.end(), this);
    if (find_stash != new_owner->_tools.end())
    {
        std::cerr << "Tool is already equiped" << std::endl; 
        return;
    }
    if (THIS_TOOL_HAS_AN_OWNER)
        this->_owner->_tools.erase(std::find(this->_owner->_tools.begin(), this->_owner->_tools.end(), this));
    this->_owner = new_owner;
    this->_owner->_tools.push_back(this);
    std::cout << "new Tool owner: " << this->_owner << std::endl;
}
    
void Tool::takeAwayFrom(Worker* worker)
{
    if (this->_owner == NULL)
    {
        std::cerr << "error: this weapon has no owner" << std::endl;
        return;
    }

    std::vector<Tool*>::iterator find_stash = std::find(worker->_tools.begin(), worker->_tools.end(), this);
    if (find_stash == this->_owner->_tools.end())
    {
        std::cerr << "error: you dont have this weapon equiped" << std::endl;
        return;
    }

    this->_owner->_tools.erase(find_stash);
    this->_owner = NULL;
}