#include "Point.h"

Point::Point(int x, int y)
	: xpos(x), ypos(y)
{

}

void Point::ShowPosition()
{
	std::cout << '[' << xpos << ", " << ypos << ']' << std::endl;
}

Point Point::operator+(const Point& ref)
{
	Point pos(xpos + ref.xpos, ypos + ref.ypos);
	return pos;
}

const Point& Point::operator+=(const Point& pos)
{
	xpos += pos.xpos;
	ypos += pos.ypos;

	return *this;
}

const Point& Point::operator-=(const Point& pos)
{
	xpos -= pos.xpos;
	ypos -= pos.ypos;

	return *this;
}

const Point& Point::operator-() const
{
	return Point(xpos * (-1), ypos * (-1));
}

const Point& operator- (const Point& pos1, const Point& pos2)
{
	return Point(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
}

bool operator==(const Point& pos1, const Point& pos2)
{
	return (pos1.xpos == pos2.xpos && pos1.ypos == pos2.ypos);
}

bool operator!=(const Point& pos1, const Point& pos2)
{
	return !(pos1 == pos2);
}

std::ostream& operator<<(std::ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Point& pos)
{
	is >> pos.xpos;
	is >> pos.ypos;
	return is;
}

Point::~Point()
{

}