#pragma once

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0);

	void ShowPosition();

	Point operator+(const Point& ref);

	void SetPos(int x, int y);

};