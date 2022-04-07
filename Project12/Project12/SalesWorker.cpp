#include "SalesWorker.h"
#include <iostream>

SalesWorker::SalesWorker(const char* name, int money, double ratio)
	: PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
{
}

void SalesWorker::AddSalesResult(int value)
{
	salesResult += value;
}

int SalesWorker::GetPay() const
{
	return PermanentWorker::GetPay()
		+ (int)(salesResult * bonusRatio);
}

void SalesWorker::ShowSalaryInfo() const
{
	ShowYourName();
	std::cout << "salary: " << GetPay() << std::endl << std::endl;
}
