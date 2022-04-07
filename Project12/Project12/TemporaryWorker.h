#pragma once
#include "Employee.h"

class TemporaryWorker : public Employee
{
private:
	int workTime;
	int payPerHour;
public:
	TemporaryWorker(const char* name, int pay);

	void AddWorkTime(int time);

	virtual int GetPay() const;

	virtual void ShowSalaryInfo() const;
};