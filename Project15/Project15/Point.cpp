#include "Point.h"
#include <iostream>

using namespace std;

Point::Point(int x, int y) : xpos(x), ypos(y)
{  }


void Point::ShowPosition()
{
	cout << '[' << xpos << ", " << ypos << ']' << endl;
}

Point Point::operator+(const Point& ref)    //operator+라는 이름의 함수
{
	Point pos(xpos + ref.xpos, ypos + ref.ypos);
	return pos;
}

void Point::SetPos(int x, int y)
{
	xpos = x;
	ypos = y;
}
