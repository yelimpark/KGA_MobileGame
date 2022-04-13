#pragma once
#include <iostream>

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0);

	void ShowPosition();

	Point operator+(const Point& ref);

	friend const Point& operator- (const Point& pos1, const Point& pos2);

	const Point& operator+=(const Point& pos);

	const Point& operator-=(const Point& pos);

	friend bool operator==(const Point& pos1, const Point& pos2);

	friend bool operator!=(const Point& pos1, const Point& pos2);

	const Point& operator-() const;

	friend std::ostream& operator<<(std::ostream& os, const Point& pos);

	friend std::istream& operator>>(std::istream& is, Point& pos);

	~Point();
};