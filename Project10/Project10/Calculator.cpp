#include "Calculator.h"
#include <iostream>

void Calculator::Init()
{
	addCouter = 0;
	mulCounter = 0;
	minCounter = 0;
	divCounter = 0;

}

float Calculator::Add(float num1, float num2)
{
	addCouter++;
	return num1 + num2;
}

float Calculator::Mul(float num1, float num2)
{
	mulCounter++;
	return num1 * num2;
}

float Calculator::Min(float num1, float num2)
{
	minCounter++;
	return num1 - num2;
}

float Calculator::Div(float num1, float num2)
{
	divCounter++;
	return num1 / num2;
}

void Calculator::ShowOpCount()
{
	std::cout << addCouter + mulCounter + minCounter + divCounter << std::endl << std::endl;
}
