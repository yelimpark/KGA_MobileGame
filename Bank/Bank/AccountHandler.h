#pragma once
#include "BoundCheckArray.h"
#include <cstdio>

class AccountHandler {
private:
	BoundCheckArray<Account *> accountArr;
	int accountArrMax;

public:
	AccountHandler();

	void MakeAccount(int bankAccountNumber, const char* name, int balance, int interest);
	
	void MakeAccount(int bankAccountNumber, const char* name, int balance, int interest, int cradit);
	
	void MakeAccount(int bankAccountNumber, my::string name, int balance, int interest);

	void MakeAccount(int bankAccountNumber, my::string name, int balance, int interest, int cradit);

	void DeleteAccount(int index);

	int FindAccount(int bankAccountNumber) const;

	void ShowAccountsInfo() const;

	void Deposit(int index, int money);

	void Withdraw(int index, int money);

	void releaseAccounts();

	//int GetAccountFile();

	//int SaveAccountFile();

	//void DepositAndWithdrawal(int sign);

	~AccountHandler();
};