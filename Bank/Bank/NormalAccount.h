#pragma once
#include "Account.h"

class NormalAccount : public Account {
protected:
	int interest;

public:
	NormalAccount(int bankAccountNumber, const char* name, int balance, int interest);
	
	NormalAccount(int bankAccountNumber, my::string name, int balance, int interest);

	NormalAccount operator=(const NormalAccount& ref);

	virtual void Deposit(int money);

	virtual void ShowAccountInfo() const;

	virtual ~NormalAccount();
};