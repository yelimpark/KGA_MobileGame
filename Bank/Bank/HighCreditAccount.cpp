#include "HighCreditAccount.h"
#include <iostream>

HighCreditAccount::HighCreditAccount(int bankAccountNumber, const char* name, int balance, int interest, int cradit)
    :Account(bankAccountNumber, name, balance), interest(interest), cradit(cradit)
{
}

int HighCreditAccount::Deposit(int money)
{
	int interestMoney = 0;

	switch (cradit)
	{
	case CRADIT_LEVEL::A:
		interestMoney = GetBalance()* (interest + 7) * 0.01;
		break;
	
	case CRADIT_LEVEL::B:
		interestMoney = GetBalance() * (interest + 4) * 0.01;
		break;

	case CRADIT_LEVEL::C:
		interestMoney = GetBalance() * (interest + 2) * 0.01;
		break;
	
	default:
		break;
	} 

	if (Account::Deposit(money + interestMoney) < 0) return -1;
	return 0;
}

void HighCreditAccount::ShowAccountInfo() const
{
	Account::ShowAccountInfo();
	std::cout << "이자율: " << interest << std::endl;
	std::cout << "신용등급(1toA, 2toB, 3toC): " << cradit << std::endl;
	std::cout << std::endl;
}

HighCreditAccount::~HighCreditAccount()
{

}
