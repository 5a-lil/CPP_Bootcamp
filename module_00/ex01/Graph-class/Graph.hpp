#pragma once
#include "../includes.hpp"

class Graph
{
    private:
        // Attributes
        Vector2 _size;
        std::map<Vector2, bool> _points;
    
    public:
        // Constructors/Destructor
        Graph(Vector2 size);
        ~Graph();

        // Getters/Setters
        void setSize(Vector2 size);
        void setPoints(std::map<Vector2, bool> points);
        Vector2 getSize();
        std::map<Vector2, bool> getPoints();

        // General-methods
        void addPoint(Vector2 point);
        void displayGraph();
};