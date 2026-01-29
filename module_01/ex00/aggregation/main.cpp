#include "Worker-class/Worker.hpp"

int main()
{
    Shovel tos;
    Worker* woft = new Worker(NULL, Position(0, 0, 0), Statistic(0, 0));
    Worker* golere = new Worker(&tos, Position(0, 0, 0), Statistic(0, 0));
    golere->useShovel();
    golere->giveShovel(*woft);
    golere->useShovel();
    woft->useShovel();
    woft->getRidOfShovel();
    woft->giveShovel(*golere);
    woft->useShovel();
    delete woft;
    delete golere;
    return 0;
}