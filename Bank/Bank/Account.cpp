#include "Account.h"
#include "WithdrawException.h"
#include "WrongMoney.h"

Account::Account(int bankAccountNumber, const char* name, int balance)
	:bankAccountNumber(bankAccountNumber), name(name), balance(balance)
{
}

Account::Account(int bankAccountNumber, my::string name, int balance)
	: bankAccountNumber(bankAccountNumber), name(name), balance(balance)
{

}

//int Account::Deposit(int money)
//{
//	if (money < 0) {
//		my::cout << "�Աݾ��� �ùٸ��� �ʽ��ϴ�." << my::endl;
//		return -1;
//	}
//
//	balance += money;
//	return 0;
//}

void Account::Withdraw(int money)
{
	if (money < 0) {
		throw WrongMoney(money);
	}
	if (money > balance) {
		throw WithdrawException(balance);
	}

	balance -= money;
}

void Account::ShowAccountInfo() const
{
	my::cout << "���¹�ȣ : " << bankAccountNumber << my::endl;
	my::cout << "�� �� : " << name << my::endl;
	my::cout << "�� �� : " << balance << my::endl;
}

int Account::GetBankAccountNumber() const
{
	return bankAccountNumber;
}

int Account::GetBalance() const
{
	return balance;
}

Account::~Account()
{
}
