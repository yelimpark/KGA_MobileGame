#include "Point.h"

class Circle {
private:
	Point midpoint;
	int radius;

public:
	Circle(int x, int y, int radius);

	int GetRadious() const;

	Point GetPos() const;

	void ShowCircle() const;
};