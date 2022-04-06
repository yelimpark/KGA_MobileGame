#include <iostream>
#include "Circle.h"

Circle::Circle(int x, int y, int radius)
	:midpoint(x, y), radius(radius)
{
}

int Circle::GetRadious() const
{
	return radius;
}

Point Circle::GetPos() const
{
	return midpoint;
}

void Circle::ShowCircle() const
{
	std::cout << radius << std::endl << std::endl;
}
