#include "HighCreditAccount.h"
#include "NormalAccount.h"
#include <cstdio>

class AccountHandler {
private:
	Account* accountArr[50];
	int accountArrMax;

public:
	AccountHandler();

	void MakeAccount(int bankAccountNumber, const char* name, int balance, int interest);
	
	void MakeAccount(int bankAccountNumber, const char* name, int balance, int interest, int cradit);

	int FindAccount(int bankAccountNumber);

	void ShowAccountsInfo();

	int GetAccountFile();

	int SaveAccountFile();

	int Deposit(int index, int money);

	int Withdraw(int index, int money);

	//void DepositAndWithdrawal(int sign);

	~AccountHandler();
};