#include "./classes/Worker.hpp"

int main()
{
    Tool* tos = new Shovel();
    Worker* woft = new Worker(NULL, Position(0, 0, 0), Statistic(0, 0));
    Worker* golere = new Worker(tos, Position(0, 0, 0), Statistic(0, 0));
    golere->useTool();
    golere->giveTool(*woft);
    golere->useTool();
    woft->useTool();
    woft->getRidOfTool();
    woft->giveTool(*golere);
    woft->useTool();
    delete woft;
    delete golere;
    delete tos;
    return 0;
}