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

        // Getters/Setters
        void setX(float x);
        void setY(float y);
        const float& getX();
        const float& getX() const;
        const float& getY();
        const float& getY() const;
};