#include "MyOs.h"
#include <cstdio>

using namespace my;

ostream& my::ostream::operator<<(char* str)
{
	printf("%s", str);
	return *this;
}

ostream& my::ostream::operator<<(const char* str)
{
	printf("%s", str);
	return *this;
}

ostream& my::ostream::operator<<(char str)
{
	printf("%c", str);
	return *this;
}

ostream& my::ostream::operator<<(int num)
{
	printf("%d", num);
	return *this;
}

ostream& my::ostream::operator<<(double e)
{
	printf("%g", e);
	return *this;
}

ostream& my::ostream::operator<<(ostream& (*fp)(ostream& ostm))
{
	return fp(*this);
}

ostream& my::endl(my::ostream& ostm)
{
	ostm << '\n';
	fflush(stdout);
	return ostm;
}
