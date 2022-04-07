#pragma once

class Account {
private:
	const int bankAccountNumber;
	char * name;
	int balance;

public:

	Account(int bankAccountNumber, const char* name, int balance);
	
	virtual int Deposit(int money) = 0;

	int Withdraw(int money);

	virtual void ShowAccountInfo() const;

	int GetBankAccountNumber() const;

	int GetBalance() const;

	virtual ~Account();
};