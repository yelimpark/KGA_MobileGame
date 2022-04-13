#include "WrongMoney.h"
#include <iostream>

WrongMoney::WrongMoney(int money)
	:money(money)
{
}

void WrongMoney::ShowExceptionReason()
{
	std::cout << std::endl << "[" << money << " : 입금불가]" << std::endl;
	std::cout << "다시 입력해 주십시오." << std::endl << std::endl;
}
