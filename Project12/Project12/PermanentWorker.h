#pragma once
#include "Employee.h"

class PermanentWorker : public Employee
{
private:
	int salary;
public:
	PermanentWorker(const char* name, int money);

	virtual int GetPay() const;

	virtual void ShowSalaryInfo() const;
};