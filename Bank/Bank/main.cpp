#include <iostream>
#include <cstdio>
#include "AccountHandler.h"

void PrintMenu() {
	std::cout << "==Menu==" << std::endl;
	std::cout << "1. ���°���" << std::endl;
	std::cout << "2. �� ��" << std::endl;
	std::cout << "3. �� ��" << std::endl;
	std::cout << "4. �������� ��ü ���" << std::endl;
	std::cout << "5. ���α׷� ����" << std::endl;
}

int main(void) {
	AccountHandler bank;
	//if (bank.GetAccountFile() != 0) {
	//	std::cout << "���� ���� ����! ���α׷��� �����մϴ�." << std::endl;
	//	return 0;
	//}

	int menu = 0;
	while (1) {
		PrintMenu();

		std::cout << "���� : ";
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
		if (1 > menu || menu > 5)  std::cout << "�߸��� ��ɾ� �Դϴ�." << std::endl << std::endl;
	}

	//if (bank.SaveAccountFile() != 0) {
	//	std::cout << "���� ���� ����!" << std::endl;
	//}

	return 0;
}