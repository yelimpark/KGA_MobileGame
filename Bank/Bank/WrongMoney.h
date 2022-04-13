#pragma once
#include "AccountException.h"

class WrongMoney : public AccountException
{
private:
	int money;

public:
	WrongMoney(int money);

	void ShowExceptionReason();
};