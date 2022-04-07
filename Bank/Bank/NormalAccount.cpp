#include "NormalAccount.h"
#include <iostream>

NormalAccount::NormalAccount(int bankAccountNumber, const char* name, int balance, int interest)
	:Account(bankAccountNumber, name, balance), interest(interest)
{

}

int NormalAccount::Deposit(int money)
{
	int interestMoney = GetBalance() * interest * 0.01;

	if (Account::Deposit(money + interestMoney) < 0) return -1;
	return 0;
}

void NormalAccount::ShowAccountInfo() const
{
	Account::ShowAccountInfo();
	std::cout << "ÀÌÀÚÀ²: " << interest << std::endl;
	std::cout << std::endl;
}

NormalAccount::~NormalAccount()
{

}
