#include "EmployeeHandler.h"

EmployeeHandler::EmployeeHandler()
	: empNum(0)
{
	memset(empList, 0, sizeof(empList));
}

void EmployeeHandler::AddEmployee(Employee* emp)
{
	empList[empNum++] = emp;
}

void EmployeeHandler::ShowAllSalaryInfo() const
{
	for (int i = 0; i < empNum; i++)
		empList[i]->ShowSalaryInfo();
}

void EmployeeHandler::ShowTotalSalary() const
{
	int sum = 0;

	for (int i = 0; i < empNum; i++)
		sum += empList[i]->GetPay();

	std::cout << "salary sum: " << sum << std::endl;
}

EmployeeHandler::~EmployeeHandler()
{
	for (int i = 0; i < empNum; i++)
		delete empList[i];
}
