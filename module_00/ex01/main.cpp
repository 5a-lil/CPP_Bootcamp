#include "./Vector2-class/Vector2.hpp"
#include "./Graph-class/Graph.hpp"

int main()
{
    Graph graph(Vector2(5, 7));
    graph.addPoint(Vector2(4, 1));
    graph.addPoint(Vector2(2, 2));
    graph.displayGraph();
}