#pragma once
#include "../includes.hpp"

class Vector2
{
    private:
        // Attributes
        float _x;
        float _y;
    
    public:
        // Constructors/Destructor
        Vector2(float x, float y);
        Vector2(const Vector2& other);
        ~Vector2();

        // Operator-overloading
        bool operator < (const Vector2& rhs) const;
        Vector2& operator = (const Vector2& rhs);
        bool operator == (const Vector2& rhs);

        // Getters/Setters
        void setX(float x);
        void setY(float y);
        const float& getX();
        const float& getX() const;
        const float& getY();
        const float& getY() const;

        // General-methods
        float dist(Vector2 other_point);
        float dist(Vector2 other_point) const;
};