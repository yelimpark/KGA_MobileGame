#include"Account.h"
#include <cstdio>

class AccountHandler {
private:
	Account* accountArr[50];
	int accountArrMax;

public:
	AccountHandler();

	void MakeAccount();

	int FindAccount(int bankAccountNumber);

	void ShowAccountsInfo();

	int GetAccountFile();

	int SaveAccountFile();

	void DepositAndWithdrawal(int sign);

	~AccountHandler();
};