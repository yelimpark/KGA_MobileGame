#include "Account.h"
#include <iostream>

Account::Account(int bankAccountNumber, const char* name, int balance)
	:bankAccountNumber(bankAccountNumber), balance(balance)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

int Account::Deposit(int money)
{
	if (money < 0) {
		std::cout << "입금액이 올바르지 않습니다." << std::endl;
		return -1;
	}

	balance += money;
	return 0;
}

int Account::Withdraw(int money)
{
	if (money < 0) {
		std::cout << "입금액이 올바르지 않습니다." << std::endl;
		return -1;
	}

	balance -= money;
	return 0;
}

void Account::ShowAccountInfo() const
{
	std::cout << "계좌번호 : " << bankAccountNumber << std::endl;
	std::cout << "이 름 : " << name << std::endl;
	std::cout << "잔 액 : " << balance << std::endl;
	std::cout << std::endl;
}

int Account::GetBankAccountNumber()
{
	return bankAccountNumber;
}

Account::~Account()
{
	delete []name;
}
