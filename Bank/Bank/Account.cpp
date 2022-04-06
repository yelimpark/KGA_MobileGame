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
		std::cout << "�Աݾ��� �ùٸ��� �ʽ��ϴ�." << std::endl;
		return -1;
	}

	balance += money;
	return 0;
}

int Account::Withdraw(int money)
{
	if (money < 0) {
		std::cout << "�Աݾ��� �ùٸ��� �ʽ��ϴ�." << std::endl;
		return -1;
	}

	balance -= money;
	return 0;
}

void Account::ShowAccountInfo() const
{
	std::cout << "���¹�ȣ : " << bankAccountNumber << std::endl;
	std::cout << "�� �� : " << name << std::endl;
	std::cout << "�� �� : " << balance << std::endl;
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
