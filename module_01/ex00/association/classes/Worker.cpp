#include "Worker.hpp"

void Worker::useTool(Tool* tool_to_use)
{
    std::vector<Tool*>::iterator find_stash = std::find(this->_tools.begin(), this->_tools.end(), tool_to_use);
    if (find_stash != this->_tools.end())
        (*find_stash)->use();
    else
        std::cerr << "Tool is not equiped to use" << std::endl;
}