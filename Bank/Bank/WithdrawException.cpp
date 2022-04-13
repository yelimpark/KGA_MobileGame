#include "WithdrawException.h"
#include <iostream>

WithdrawException::WithdrawException(int money)
	:balance(money)
{
}

void WithdrawException::ShowExceptionReason()
{
	std::cout << std::endl << "[잔액 " << balance << ", 잔액부족]" << std::endl;
	std::cout << "다시 입력해 주십시오." << std::endl << std::endl;
}
