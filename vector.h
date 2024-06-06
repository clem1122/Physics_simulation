#pragma once

class Vector{
private:
	double x;
	double y;
public:
	Vector();
	Vector(double x, double y);
	
	void print();
	Vector operator+(const Vector &v) const;
	Vector operator-(const Vector &v) const;
	
};
