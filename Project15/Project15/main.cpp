#include <iostream>
#include "Point.h"
#include "SmartPtr.h"

int main(void)
{
	int* num = new int(10);
	SmartPtr<int> sptri(num);
	std::cout << *sptri << std::endl;

	SmartPtr<Point> sptr1(new Point(1, 2));
	SmartPtr<Point> sptr2(new Point(3, 4));
	sptr1->ShowPosition();
	sptr2->ShowPosition();

	sptr1->SetPos(10, 20);
	sptr2->SetPos(30, 40);
	sptr1->ShowPosition();
	sptr2->ShowPosition();

	return 0;
}