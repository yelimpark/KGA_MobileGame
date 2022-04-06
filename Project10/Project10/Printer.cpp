#include "Printer.h"
#include <cstring>
#include <iostream>

void Printer::SetString(const char* str)
{
	this->str = new char[strlen(str) + 1];
	strcpy_s(this->str, strlen(str) + 1, str);
}

void Printer::ShowString()
{
	std::cout << str << std::endl;
}

Printer::~Printer()
{
	delete[] str;
}
