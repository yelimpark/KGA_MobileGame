#include <iostream>
#include <cstdio>
#include "AccountHandler.h"

void PrintMenu() {
	std::cout << "==Menu==" << std::endl;
	std::cout << "1. 계좌개설" << std::endl;
	std::cout << "2. 입 금" << std::endl;
	std::cout << "3. 출 금" << std::endl;
	std::cout << "4. 계좌정보 전체 출력" << std::endl;
	std::cout << "5. 프로그램 종료" << std::endl;
}

int main(void) {
	AccountHandler bank;
	//if (bank.GetAccountFile() != 0) {
	//	std::cout << "파일 오픈 실패! 프로그램을 종료합니다." << std::endl;
	//	return 0;
	//}

	int menu = 0;
	while (1) {
		PrintMenu();

		std::cout << "선택 : ";
		std::cin >> menu;
		std::cout << std::endl;

		switch (menu)
		{
		case 1: {
			bank.MakeAccount();
			break;
		}
		case 2: {
			bank.DepositAndWithdrawal(1);
			break;
		}
		case 3: {
			bank.DepositAndWithdrawal(-1);
			break;
		}
		case 4: {
			bank.ShowAccountsInfo();
			break;
		}

		default:
			break;
		}

		if (menu == 5) break;
		if (1 > menu || menu > 5)  std::cout << "잘못된 명령어 입니다." << std::endl << std::endl;
	}

	//if (bank.SaveAccountFile() != 0) {
	//	std::cout << "파일 저장 실패!" << std::endl;
	//}

	return 0;
}