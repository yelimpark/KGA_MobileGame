#include <iostream>
#include "Point.h"
using namespace std;

Point::Point(const int& xpos, const int& ypos)
	: x(xpos), y(ypos)
{

}

int Point::GetX() const { return x; }
int Point::GetY() const { return y; }

bool Point::SetX(int xpos)
{
	if (0 > xpos || xpos > 100)
	{
		cout << "벗어난 범위의 값 전달" << endl;
		return false;
	}

	x = xpos;
	return true;
}
bool Point::SetY(int ypos)
{
	if (0 > ypos || ypos > 100)
	{
		cout << "벗어난 범위의 값 전달" << endl;
		return false;
	}

	y = ypos;
	return true;
}

void Point::MovePos(int x, int y)
{
	SetX(this->x + x);
	SetY(this->y + y);
}

void Point::AddPoint(const Point& pos)
{
	SetX(x + pos.GetX());
	SetY(y + pos.GetY());
}

void Point::ShowPosition()
{
	std::cout << "[" << GetX() << ", " << GetY() << "]" << std::endl << std::endl;
}
