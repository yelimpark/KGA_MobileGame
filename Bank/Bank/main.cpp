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
			std::cout << "[������������]" << std::endl;
			std::cout << "1. ���뿹�ݰ���" << std::endl;
			std::cout << "2. �ſ�ŷڰ���" << std::endl;

			int accountType = 0;
			std::cout << "����: ";
			std::cin >> accountType;
			std::cout << std::endl;

			if (accountType < 1 || 2 < accountType) {
				std::cout << "�߸��� ��ɾ� �Դϴ�." << std::endl << std::endl;
				break;
			}

			int bankAccountNumber = 0;
			char name[100] = " ";
			int balance = 0;
			int interest = 0;

			if (accountType == 1) {
				std::cout << "[���뿹�ݰ��°���]" << std::endl;

			}
			else if (accountType == 2) {
				std::cout << "[�ſ�ŷڰ��°���]" << std::endl;
			}

			std::cout << "���¹�ȣ : ";
			std::cin >> bankAccountNumber;
			std::cout << "�̸� : ";
			std::cin >> name;
			std::cout << "�Աݾ� : ";
			std::cin >> balance;
			std::cout << "������ : ";
			std::cin >> interest;
			
			if (accountType == 1) {
				std::cout << std::endl;
				bank.MakeAccount(bankAccountNumber, name, balance, interest);
			}
			else if (accountType == 2) {
				int cradit = 0;
				std::cout << "�ſ���(1toA, 2toB, 3toC) : ";
				std::cin >> cradit;
				std::cout << std::endl;
				bank.MakeAccount(bankAccountNumber, name, balance, interest, cradit);
			}

			break;
		}
		case 2: {
			std::cout << "[�� ��]" << std::endl;

			int bankAccountNumber = 0;
			std::cout << "���¹�ȣ : ";
			std::cin >> bankAccountNumber;

			int index = bank.FindAccount(bankAccountNumber);

			if (index < 0) {
				std::cout << "���� ������ ã�� ���߽��ϴ�." << std::endl;
				std::cout << "�ٽ� �޴��� ���ư��ϴ�." << std::endl << std::endl;
				break;
			}

			int money = 0;
			std::cout << "�Աݾ� : ";
			std::cin >> money;

			bank.Deposit(index, money);

			std::cout << "�Ա� �Ϸ�" << std::endl << std::endl;
			
			break;
		}
		case 3: {
			std::cout << "[�� ��]" << std::endl;

			int bankAccountNumber = 0;
			std::cout << "���¹�ȣ : ";
			std::cin >> bankAccountNumber;

			int index = bank.FindAccount(bankAccountNumber);

			if (index < 0) {
				std::cout << "���� ������ ã�� ���߽��ϴ�." << std::endl;
				std::cout << "�ٽ� �޴��� ���ư��ϴ�." << std::endl << std::endl;
				break;
			}

			int money = 0;
			std::cout << "��ݾ� : ";
			std::cin >> money;

			bank.Withdraw(index, money);

			std::cout << "��� �Ϸ�" << std::endl << std::endl;

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