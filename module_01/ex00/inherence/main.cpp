#include "./classes/Worker.hpp"
#include "./classes/Shovel.hpp"
#include "./classes/Hammer.hpp"

int main()
{
    Tool* tos = new Shovel;
    Worker* woft = new Worker;
    Worker* golere = new Worker;
    std::cout << "woft address: "<< woft << std::endl;
    std::cout << "golere address: "<< golere << std::endl;
    tos->giveTo(woft);
    tos->giveTo(woft);
    tos->giveTo(golere);

    tos->use();
    tos->giveTo(woft);
    tos->giveTo(golere);
    golere->useTool(tos);
    tos->takeAwayFrom(golere);
    golere->useTool(tos);
    golere->useTool(NULL);
    delete woft;
    delete golere;
    delete tos;
    return 0;
}