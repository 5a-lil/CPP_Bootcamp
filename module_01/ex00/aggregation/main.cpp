#include "Worker-class/Worker.hpp"

int main()
{
    Shovel* tos = new Shovel;
    Worker* woft = new Worker;
    Worker* golere = new Worker;
    std::cout << "woft address: "<< woft << std::endl;
    std::cout << "golere address: "<< golere << std::endl;
    tos->giveTo(woft);
    tos->giveTo(woft);
    tos->giveTo(golere);
    golere->useShovel();
    delete woft;
    delete golere;
    return 0;
}