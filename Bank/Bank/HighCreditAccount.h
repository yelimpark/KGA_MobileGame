#pragma once
#include "Account.h"

namespace CRADIT_LEVEL {
	enum {
		A = 1,
		B,
		C
	};
}

class HighCreditAccount : public Account {
private:
	int interest;
	int cradit;

public:
	HighCreditAccount(int bankAccountNumber, const char* name, int balance, int interest, int cradit);

	virtual int Deposit(int money);

	virtual void ShowAccountInfo() const;

	virtual ~HighCreditAccount();
};