#include "./Vector2-class/Vector2.hpp"
#include "./Graph-class/Graph.hpp"

int main()
{
    try {
    Graph graph(Vector2(10, 10));
    // std::cout << Vector2(1, 1).dist(Vector2(0, 0)) << std::endl;
    graph.addPoint(Vector2(0.77, 0));
    // graph.addPoint(Vector2(2.2, 2));
    // graph.addPoint(Vector2(2.9, 2));
    // graph.addPoint(Vector2(2, 4));
    graph.displayGraph();
    graph.addPoint(Vector2(-1, 0));
    } catch (std::exception& e) {
        std::cerr << "Exception catched: " << e.what() << std::endl;
    }
}