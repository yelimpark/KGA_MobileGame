#include "Employee.h"
#include <iostream>
#include <cstring>

Employee::Employee(const char* name)
{
	strcpy_s(this->name, strlen(name) + 1, name);
}

void Employee::ShowYourName() const
{
	std::cout << "name: " << name << std::endl;
}
