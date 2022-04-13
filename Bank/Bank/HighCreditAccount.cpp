#include "HighCreditAccount.h"
#include <iostream>
#include "WrongMoney.h"

HighCreditAccount::HighCreditAccount(int bankAccountNumber, const char* name, int balance, int interest, CRADIT_LEVEL cradit)
    :NormalAccount(bankAccountNumber, name, balance, interest), cradit(cradit)
{
}

HighCreditAccount::HighCreditAccount(int bankAccountNumber, my::string name, int balance, int interest, CRADIT_LEVEL cradit)
	: NormalAccount(bankAccountNumber, name, balance, interest), cradit(cradit)
{
}

HighCreditAccount HighCreditAccount::operator=(const HighCreditAccount& ref)
{
	name = ref.name;
	bankAccountNumber = ref.bankAccountNumber;
	balance = ref.balance;
	interest = ref.interest;
	cradit = ref.cradit;

	return *this;
}

void HighCreditAccount::Deposit(int money)
{
	if (money < 0) {
		throw WrongMoney(money);
	}

	int interestMoney = 0;

	switch (cradit)
	{
	case CRADIT_LEVEL::A:
		interestMoney = balance * (interest + 7) * 0.01;
		break;
	
	case CRADIT_LEVEL::B:
		interestMoney = balance * (interest + 4) * 0.01;
		break;

	case CRADIT_LEVEL::C:
		interestMoney = balance * (interest + 2) * 0.01;
		break;
	
	default:
		break;
	}

	balance += (money + interestMoney);
}

void HighCreditAccount::ShowAccountInfo() const
{
	Account::ShowAccountInfo();
	std::cout << "이자율: " << interest << std::endl;
	switch (cradit)
	{
	case CRADIT_LEVEL::A:
		std::cout << "신용등급: A" << std::endl;
		break;
	case CRADIT_LEVEL::B:
		std::cout << "신용등급: B" << std::endl;
		break;
	case CRADIT_LEVEL::C:
		std::cout << "신용등급: C" << std::endl;
		break;
	default:
		break;
	}
	
	std::cout << std::endl;
}

HighCreditAccount::~HighCreditAccount()
{

}
