#include "WrongMoney.h"
#include <iostream>

WrongMoney::WrongMoney(int money)
	:money(money)
{
}

void WrongMoney::ShowExceptionReason()
{
	std::cout << std::endl << "[" << money << " : �ԱݺҰ�]" << std::endl;
	std::cout << "�ٽ� �Է��� �ֽʽÿ�." << std::endl << std::endl;
}
