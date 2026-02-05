#include "Worker-class/Worker.hpp"

int main()
{
    Shovel* tos = new Shovel;
    Worker* woft = new Worker;
    Worker* golere = new Worker;
    std::cout << "woft address: "<< woft << std::endl;
    std::cout << "golere address: "<< golere << std::endl;
    woft->equipShovel(tos);
    std::cout << tos->_owner << std::endl;
    woft->useShovel();
    golere->equipShovel(tos);
    std::cout << tos->_owner << std::endl;
    woft->useShovel();
    golere->unequipShovel();
    std::cout << tos->_owner << std::endl;
    golere->useShovel();
    delete woft;
    delete golere;
    return 0;
}