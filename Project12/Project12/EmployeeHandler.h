#pragma once
#include "SalesWorker.h"
#include "PermanentWorker.h"
#include "TemporaryWorker.h"
#include "ForeignSalesWorker.h"

#include <iostream>

class EmployeeHandler
{
private:
	Employee* empList[50];
	int empNum;
public:
	EmployeeHandler();

	void AddEmployee(Employee* emp);

	void ShowAllSalaryInfo() const;

	void ShowTotalSalary() const;

	~EmployeeHandler();
};