#include "Vector2.hpp"

Vector2::Vector2(float x, float y) : _x(x), _y(y) {}

Vector2::~Vector2() {}

void Vector2::setX(float x) { this->_x = x; }

void Vector2::setY(float y) { this->_y = y; }

const float& Vector2::getX() { return this->_x; }

const float& Vector2::getX() const { return this->_x; }

const float& Vector2::getY() { return this->_y; }

const float& Vector2::getY() const { return this->_y; }
