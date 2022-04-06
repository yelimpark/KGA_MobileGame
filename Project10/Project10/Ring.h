#include "Circle.h"

class Ring {
private:
	Circle c1;
	Circle c2;

public:
	Ring(int x1, int y1, int r1, int x2, int y2, int r2);

	void ShowRing() const;
};