#ifndef __POINT_H_
#define __POINT_H_

class Point
{
	int x;
	int y;
public:
	Point(const int& xpos, const int& ypos);
	int GetX() const;
	int GetY() const;
	bool SetX(int xpos);
	bool SetY(int ypos);

	void MovePos(int x, int y);
	void AddPoint(const Point& pos);
	void ShowPosition();


};

#endif