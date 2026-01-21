#include "includes.hpp" 
#pragma once 

class Vector2
{
    private:
        // Attributes
        float _x;
        float _y;
    
    public:
        // Constructors/Destructor
        Vector2(float x, float y);
        ~Vector2();

        // Operator-overloading
        friend bool operator < (Vector2 const& lhs, Vector2 const& rhs) { return lhs.norm() < rhs.norm(); }

        // Getters/Setters
        void setX(float x);
        void setY(float y);
        const float& getX();
        const float& getX() const;
        const float& getY();
        const float& getY() const;

        // General-methods
        float norm();
        float norm() const;
};