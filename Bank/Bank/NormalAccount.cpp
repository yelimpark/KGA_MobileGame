#include "NormalAccount.h"
#include <iostream>
#include "WrongMoney.h"

NormalAccount::NormalAccount(int bankAccountNumber, const char* name, int balance, int interest)
	:Account(bankAccountNumber, name, balance), interest(interest)
{

}

NormalAccount::NormalAccount(int bankAccountNumber, my::string name, int balance, int interest)
	: Account(bankAccountNumber, name, balance), interest(interest)
{

}

NormalAccount NormalAccount::operator=(const NormalAccount& ref)
{
	name = ref.name;
	bankAccountNumber = ref.bankAccountNumber;
	balance = ref.balance;
	interest = ref.interest;

	return *this;
}

void NormalAccount::Deposit(int money)
{
	if (money < 0) {
		throw WrongMoney(money);
	}

	int interestMoney = balance * interest * 0.01;

	balance += (money + interestMoney);
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
