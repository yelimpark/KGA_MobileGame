#pragma once
#include "Account.h"

class NormalAccount : public Account {
private:
	int interest;

public:
	NormalAccount(int bankAccountNumber, const char* name, int balance, int interest);

	virtual int Deposit(int money);

	virtual void ShowAccountInfo() const;

	virtual ~NormalAccount();
};