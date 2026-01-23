#pragma once
#include "../includes.hpp"

class Graph
{
    private:
        // Exceptions
        class NegativeOrZeroConstructorError : public std::exception
		{
			public:
                const char* what() const throw ();
		};
        class TooLargeConstructorError : public std::exception
		{
			public:
                const char* what() const throw ();
		};
        class OutOfBoundsPoint : public std::exception
		{
			public:
                const char* what() const throw ();
		};

        // Attributes
        Vector2 _size;
        std::map<Vector2, bool> _points;
    
    public:
        // Constructors/Destructor
        Graph(Vector2 size);
        ~Graph();

        // Getters/Setters
        // void setSize(Vector2 size);
        // void setPoints(std::map<Vector2, bool> points);
        const Vector2& getSize();
        const std::map<Vector2, bool>& getPoints();

        // General-methods
        void addPoint(Vector2 point);
        void displayGraph();
};