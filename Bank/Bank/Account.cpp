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
//		my::cout << "입금액이 올바르지 않습니다." << my::endl;
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
	my::cout << "계좌번호 : " << bankAccountNumber << my::endl;
	my::cout << "이 름 : " << name << my::endl;
	my::cout << "잔 액 : " << balance << my::endl;
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
