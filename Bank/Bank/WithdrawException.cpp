#include "WithdrawException.h"
#include <iostream>

WithdrawException::WithdrawException(int money)
	:balance(money)
{
}

void WithdrawException::ShowExceptionReason()
{
	std::cout << std::endl << "[�ܾ� " << balance << ", �ܾ׺���]" << std::endl;
	std::cout << "�ٽ� �Է��� �ֽʽÿ�." << std::endl << std::endl;
}
