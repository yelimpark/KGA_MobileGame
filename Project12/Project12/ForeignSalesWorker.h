#include "SalesWorker.h"

enum RISK_LEVEL {
	RISK_A = 0,
	RISK_B,
	RISK_C
};

class ForeignSalesWorker : public SalesWorker {
private:
	const int risk;

public:
	ForeignSalesWorker(const char* name, int money, double ratio, RISK_LEVEL risk);

	virtual int GetPay() const;

	virtual void ShowSalaryInfo() const;
};