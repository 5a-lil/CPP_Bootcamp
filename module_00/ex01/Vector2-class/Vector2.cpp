#include "Vector2.hpp"

Vector2::Vector2(float x, float y) : _x(x), _y(y) {}

Vector2::Vector2(const Vector2& other)
{
    *this = other;
}

Vector2::~Vector2() {}

bool Vector2::operator < (const Vector2& rhs) const 
{ 
    if (this->getY() < rhs.getY()) return true;
    if (this->getY() > rhs.getY()) return false;
    return this->getX() < rhs.getX(); 
}

Vector2& Vector2::operator = (const Vector2& rhs)
{
    if (&rhs == this)
        return *this;
    this->_x = rhs._x;
    this->_y = rhs._y;
    return *this;
}

bool Vector2::operator == (const Vector2& rhs)
{
    return this->_x == rhs._x && this->_y == rhs._y;
}

void Vector2::setX(float x) { this->_x = x; }

void Vector2::setY(float y) { this->_y = y; }

const float& Vector2::getX() { return this->_x; }

const float& Vector2::getX() const { return this->_x; }

const float& Vector2::getY() { return this->_y; }

const float& Vector2::getY() const { return this->_y; }

float Vector2::norm() { return std::sqrt(std::pow(this->_x, 2) + std::pow(this->_y, 2)); }

float Vector2::norm() const { return std::sqrt(std::pow(this->_x, 2) + std::pow(this->_y, 2)); }
