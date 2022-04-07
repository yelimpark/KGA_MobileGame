#pragma once
#include "PermanentWorker.h"

class SalesWorker : public PermanentWorker
{
private:
	int salesResult;    // �� �ǸŽ���
	double bonusRatio;    // �󿩱� ���� 
public:
	SalesWorker(const char* name, int money, double ratio);

	void AddSalesResult(int value);

	virtual int GetPay() const;

	virtual void ShowSalaryInfo() const;
};
