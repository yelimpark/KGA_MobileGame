#include <iostream>

// 2.1
void PlusOne(int &num) {
	num++;
}

void ReversalSign(int& num) {
	num *= (-1);
}

// 2.3
void SwapPointer(int* (&pref1), int* (&pref2)) {
	int * tmp = pref1;
	pref1 = pref2;
	pref2 = tmp;
}

// 2.5
typedef struct __Point
{
	int xpos;
	int ypos;
} Point;

Point& PntAdder(const Point& p1, const Point& p2) {
	Point* res = new Point;
	res->xpos = p1.xpos + p2.xpos;
	res->ypos = p1.ypos + p2.ypos;

	return *res;
}

int main() {
	// 2.1
	int num = -2;

	std::cout << num << std::endl;

	PlusOne(num);
	std::cout << num << std::endl;

	ReversalSign(num);
	std::cout << num << std::endl;

	// 2.3
	int num1 = 5;
	int* ptr1 = &num1;
	int num2 = 10;
	int* ptr2 = &num2;
	std::cout << *ptr1 << " " << *ptr2 << std::endl;
	SwapPointer(ptr1, ptr2);
	std::cout << *ptr1 << " " << *ptr2 << std::endl;

	// 2.4
	const int num3 = 12;
	const int* iptr = &num3;
	const int* (&pref) = iptr;
	std::cout << *iptr << " " << *pref << std::endl;

	// 2.5
	Point* p1 = new Point({ 3,3 });
	Point* p2 = new Point({ 2,2 });

	Point& res = PntAdder(*p1, *p2);

	std::cout << "(" << res.xpos << "," << res.ypos << ")" << std::endl;

	delete p1;
	delete p2;
	delete& res;

	return 0;
}