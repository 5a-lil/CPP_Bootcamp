#include "Vector2.hpp"

Vector2::Vector2(float x, float y) : _x(x), _y(y) {}

Vector2::~Vector2() {}

void Vector2::setX(float x) { this->_x = x; }

void Vector2::setY(float y) { this->_y = y; }

const float& Vector2::getX() { return this->_x; }

const float& Vector2::getX() const { return this->_x; }

const float& Vector2::getY() { return this->_y; }

const float& Vector2::getY() const { return this->_y; }

float Vector2::norm() { return std::sqrt(std::pow(this->_x, 2) + std::pow(this->_y, 2)); }

float Vector2::norm() const { return std::sqrt(std::pow(this->_x, 2) + std::pow(this->_y, 2)); }
