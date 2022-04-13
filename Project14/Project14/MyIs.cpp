#include "MyIs.h"
#include <cstdio>

using namespace my;

istream& my::istream::operator>>(const char* str)
{
    scanf_s("%s", str, (int)sizeof(str));
    return *this;
}
