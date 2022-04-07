#include "ForeignSalesWorker.h"
#include <iostream>

ForeignSalesWorker::ForeignSalesWorker(const char* name, int money, double ratio, RISK_LEVEL risk)
    :SalesWorker(name, money, ratio), risk(risk)
{
}

int ForeignSalesWorker::GetPay() const
{
	switch (risk)
	{
	case RISK_A :
		return (int)(SalesWorker::GetPay() * 1.3);
	
	case RISK_B :
		return (int)(SalesWorker::GetPay() * 1.2);
	
	case RISK_C :
		return (int)(SalesWorker::GetPay() * 1.1);
	
	default:
		break;
	}
		
	std::cout << "risk 타입이 이상합니다." << std::endl;
	return 0;
}

void ForeignSalesWorker::ShowSalaryInfo() const
{
	ShowYourName();
	std::cout << "salary: " << SalesWorker::GetPay() << std::endl;
	std::cout << "risk pay: " << GetPay() - SalesWorker::GetPay() << std::endl;
	std::cout << "salary: " << GetPay() << std::endl << std::endl;
}
