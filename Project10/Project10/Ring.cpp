#include "Ring.h"
#include <cmath>
#include <iostream>

Ring::Ring(int x1, int y1, int r1, int x2, int y2, int r2)
	:c1(x1, y1, r1), c2(x2, y2, r2)
{
	const Point& pos1 = c1.GetPos();
	const Point& pos2 = c2.GetPos();

	float dis = sqrt((pos1.GetX() - pos2.GetX()) * (pos1.GetX() - pos2.GetX()) +
		(pos1.GetY() - pos2.GetY()) * (pos1.GetY() - pos2.GetY()));

	int diffInRadius = (c1.GetRadious() > c2.GetRadious()) ? c1.GetRadious() - c2.GetRadious() : c2.GetRadious() - c1.GetRadious();

	if (diffInRadius < (float)dis && diffInRadius != 0) {
		Circle initialCircle(0,0,0);
		c1 = initialCircle;
		c2 = initialCircle;
	}
}

void Ring::ShowRing() const
{
	std::cout << "cirle 1 mid point : (" << c1.GetPos().GetX() << ", " << c1.GetPos().GetY() << ")" << std::endl;
	std::cout << "circle 1 radious : " << c1.GetRadious() << std::endl;
	std::cout << "cirle 2 mid point : (" << c2.GetPos().GetX() << ", " << c2.GetPos().GetY() << ")" << std::endl;
	std::cout << "circle 2 radious : " << c2.GetRadious() << std::endl << std::endl;
}
