#include "./classes/Worker.hpp"
#include "./classes/Shovel.hpp"
#include "./classes/Hammer.hpp"
#include "./classes/Workshop.hpp"

int main()
{
    Worker woft;
    Worker golere;
    Workshop w;
    Workshop x;
    w.executeWorkDay();
    w.manageWorkers(&woft, "register");
    w.manageWorkers(&woft, "register");
    w.manageWorkers(&golere, "release");
    w.executeWorkDay();
    w.manageWorkers(&golere, "register");
    w.manageWorkers(&golere, "register");
    w.executeWorkDay();
    x.manageWorkers(&golere, "register");
    x.executeWorkDay();
}