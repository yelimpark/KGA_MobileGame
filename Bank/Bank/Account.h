#pragma once
#include "MyString.h"

class Account {
protected:
	int bankAccountNumber;
	my::string name;
	int balance;

public:

	Account(int bankAccountNumber, const char* name, int balance);
	
	Account(int bankAccountNumber, my::string name, int balance);

	virtual void Deposit(int money) = 0;

	void Withdraw(int money);

	virtual void ShowAccountInfo() const;

	int GetBankAccountNumber() const;

	int GetBalance() const;

	virtual ~Account();
};