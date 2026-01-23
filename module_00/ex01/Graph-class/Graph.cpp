#include "Graph.hpp"
#define EXISTS true
#define NOT_EXISTS false

const char* Graph::NegativeOrZeroConstructorError::what() const throw () { return "Constructor parameters are negative or equal to 0"; }

const char* Graph::TooLargeConstructorError::what() const throw () { return "Constructor parameters are too large must be <=10"; }

const char* Graph::OutOfBoundsPoint::what() const throw () { return "Point trying to be added to graph is out of bounds of graph size"; }

Graph::Graph(Vector2 size) : _size(size) { if (size.getX() <= 0 || size.getY() <= 0) throw NegativeOrZeroConstructorError(); 
                                           if (size.getX() > 10 || size.getY() > 10) throw TooLargeConstructorError();}

Graph::~Graph() {}

// void Graph::setSize(Vector2 size) { this->_size = size; }

// void Graph::setPoints(std::map<Vector2, bool> points) { this->_points = points; }

const Vector2& Graph::getSize() { return this->_size; }

const std::map<Vector2, bool>& Graph::getPoints() { return this->_points; }

void Graph::addPoint(Vector2 point) { 
    if (point.getX() >= this->_size.getX() || 
        point.getY() >= this->_size.getY() ||
        point.getX() < 0 ||
        point.getY() < 0) throw OutOfBoundsPoint();
    this->_points.insert(std::make_pair(Vector2((int)point.getX(), (int)point.getY()), true)); 
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