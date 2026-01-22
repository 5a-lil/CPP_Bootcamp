#include "Graph.hpp"
#define EXISTS true
#define NOT_EXISTS false

Graph::Graph(Vector2 size) : _size(size) {}

Graph::~Graph() {}

void Graph::setSize(Vector2 size) { this->_size = size; }

void Graph::setPoints(std::map<Vector2, bool> points) { this->_points = points; }

Vector2 Graph::getSize() { return this->_size; }

std::map<Vector2, bool> Graph::getPoints() { return this->_points; }

void Graph::addPoint(Vector2 point) { 
    this->_points.insert(std::make_pair(point, true)); 
}

void Graph::displayGraph()
{
    int width = this->_size.getX();
    int height = this->_size.getY();

    for (int y = 0; y < height; y++)
    {
        std::cout << std::abs(height - y - 1) << " ";
        for (int x = 0; x < width; x++)
        {
            if (this->_points[Vector2(x, height - y - 1)])
            {
                std::cout << "X "; continue;
            }
            std::cout << ". ";
        }
        std::cout << std::endl;
    }

    std::cout << "  ";
    for (int i = 0; i < width; i++)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

}