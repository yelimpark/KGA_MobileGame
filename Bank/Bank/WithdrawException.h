#pragma once
#include "AccountException.h"

class WithdrawException : public AccountException
{
private:
	int balance;

public:
	WithdrawException(int money);

	void ShowExceptionReason();
};