#include "AccountHandler.h"
#include <iostream>

AccountHandler::AccountHandler()
	:accountArr(50),accountArrMax(0)
{

}

void AccountHandler::MakeAccount(int bankAccountNumber, const char* name, int balance, int interest)
{
	if (FindAccount(bankAccountNumber) >= 0) {
		std::cout << "중복된 계좌번호 입니다." << std::endl << std::endl;
		return;
	}
	accountArr[accountArrMax++] = new NormalAccount(bankAccountNumber, name, balance, interest);
}

void AccountHandler::MakeAccount(int bankAccountNumber, const char* name, int balance, int interest, int cradit)
{
	if (FindAccount(bankAccountNumber) >= 0) {
		std::cout << "중복된 계좌번호 입니다." << std::endl << std::endl;
		return;
	}
	
	if (cradit == 1)
		accountArr[accountArrMax++] = new HighCreditAccount(bankAccountNumber, name, balance, interest, CRADIT_LEVEL::A);
	else if (cradit == 2)
		accountArr[accountArrMax++] = new HighCreditAccount(bankAccountNumber, name, balance, interest, CRADIT_LEVEL::B);
	else
		accountArr[accountArrMax++] = new HighCreditAccount(bankAccountNumber, name, balance, interest, CRADIT_LEVEL::C);
}

void AccountHandler::MakeAccount(int bankAccountNumber, my::string name, int balance, int interest)
{
	if (FindAccount(bankAccountNumber) >= 0) {
		std::cout << "중복된 계좌번호 입니다." << std::endl << std::endl;
		return;
	}
	accountArr[accountArrMax++] = new NormalAccount(bankAccountNumber, name, balance, interest);
}

void AccountHandler::MakeAccount(int bankAccountNumber, my::string name, int balance, int interest, int cradit)
{
	if (FindAccount(bankAccountNumber) >= 0) {
		std::cout << "중복된 계좌번호 입니다." << std::endl << std::endl;
		return;
	}

	if (cradit == 1)
		accountArr[accountArrMax++] = new HighCreditAccount(bankAccountNumber, name, balance, interest, CRADIT_LEVEL::A);
	else if (cradit == 2)
		accountArr[accountArrMax++] = new HighCreditAccount(bankAccountNumber, name, balance, interest, CRADIT_LEVEL::B);
	else
		accountArr[accountArrMax++] = new HighCreditAccount(bankAccountNumber, name, balance, interest, CRADIT_LEVEL::C);
}

void AccountHandler::DeleteAccount(int index)
{
	delete accountArr[index];
	accountArr.RemoveBCA(index, accountArrMax);
	--accountArrMax;
}

int AccountHandler::FindAccount(int bankAccountNumber) const
{
	for (int i = 0; i < accountArrMax; i++) {
		if (accountArr[i] -> GetBankAccountNumber() == bankAccountNumber) {
			return i;
		}
	}
	return -1;
}

void AccountHandler::ShowAccountsInfo() const
{
	for (int i = 0; i < accountArrMax; i++) {
		accountArr[i]->ShowAccountInfo();
	}
}

void AccountHandler::Deposit(int index, int money)
{
	accountArr[index]->Deposit(money);
}

void AccountHandler::Withdraw(int index, int money)
{
	accountArr[index]->Withdraw(money);
}

void AccountHandler::releaseAccounts()
{
	for (int i = 0; i < accountArrMax; i++) {
		delete accountArr[i];
	}
}

AccountHandler::~AccountHandler()
{

}

