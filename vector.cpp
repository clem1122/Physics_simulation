#include "vector.h"
#include <iostream>

Vector::Vector(){
	x = 0;
	y = 0;
}

Vector::Vector(double _x, double _y) {
	x = _x;
	y = _y;
}

void Vector::print(){
	std::cout << "(" << x << "," << y << ")" << std::endl;
}

Vector Vector::operator+(const Vector &v) const{
	return Vector(x + v.x, y + v.y);
}

Vector Vector::operator-(const Vector &v) const{
	return Vector(x - v.x, y - v.y);
}
