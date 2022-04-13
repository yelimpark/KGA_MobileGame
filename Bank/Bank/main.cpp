#include <cstdio>
#include "AccountHandler.h"
#include "WithdrawException.h"
#include "WrongMoney.h"

int main(void) {
	AccountHandler bank;

	int menu = 0;
	while (1) {
		my::cout << "==Menu==" << my::endl;
		my::cout << "1. ���°���" << my::endl;
		my::cout << "2. �� ��" << my::endl;
		my::cout << "3. �� ��" << my::endl;
		my::cout << "4. �������� ��ü ���" << my::endl;
		my::cout << "5. ���� ����" << my::endl;
		my::cout << "6. ���α׷� ����" << my::endl;

		my::cout << "���� : ";
		my::cin >> menu;
		my::cout << my::endl;

		switch (menu)
		{
		case 1: {
			my::cout << "[������������]" << my::endl;
			my::cout << "1. ���뿹�ݰ���" << my::endl;
			my::cout << "2. �ſ�ŷڰ���" << my::endl;

			int accountType = 0;
			my::cout << "����: ";
			my::cin >> accountType;
			my::cout << my::endl;

			if (accountType < 1 || 2 < accountType) {
				my::cout << "�߸��� ��ɾ� �Դϴ�." << my::endl << my::endl;
				my::cout << "�ٽ� �޴��� ���ư��ϴ�." << my::endl << my::endl;
				break;
			}

			int bankAccountNumber = 0;
			char name[100] = " ";
			int balance = 0;
			int interest = 0;

			if (accountType == 1) {
				my::cout << "[���뿹�ݰ��°���]" << my::endl;

			}
			else if (accountType == 2) {
				my::cout << "[�ſ�ŷڰ��°���]" << my::endl;
			}

			my::cout << "���¹�ȣ : ";
			my::cin >> bankAccountNumber;
			my::cout << "�̸� : ";
			my::cin >> name;
			my::cout << "�Աݾ� : ";
			my::cin >> balance;
			my::cout << "������ : ";
			my::cin >> interest;
			
			if (accountType == 1) {
				my::cout << my::endl;
				bank.MakeAccount(bankAccountNumber, name, balance, interest);
			}
			else if (accountType == 2) {
				int cradit = 0;
				my::cout << "�ſ���(1toA, 2toB, 3toC) : ";
				my::cin >> cradit;
				my::cout << my::endl;
				bank.MakeAccount(bankAccountNumber, name, balance, interest, cradit);
			}

			break;
		}
		case 2: {
			my::cout << "[�� ��]" << my::endl;

			int bankAccountNumber = 0;
			my::cout << "���¹�ȣ : ";
			my::cin >> bankAccountNumber;

			int index = bank.FindAccount(bankAccountNumber);

			if (index < 0) {
				my::cout << "���� ������ ã�� ���߽��ϴ�." << my::endl;
				my::cout << "�ٽ� �޴��� ���ư��ϴ�." << my::endl << my::endl;
				break;
			}

			int money = 0;
			
			while (1) {
				my::cout << "�Աݾ� : ";
				my::cin >> money;

				try {
					bank.Deposit(index, money);

					my::cout << "�Ա� �Ϸ�" << my::endl << my::endl;
					break;
				}
				catch (AccountException& expn) {
					expn.ShowExceptionReason();
				}
			}
			
			break;
		}
		case 3: {
			my::cout << "[�� ��]" << my::endl;

			int bankAccountNumber = 0;
			my::cout << "���¹�ȣ : ";
			my::cin >> bankAccountNumber;

			int index = bank.FindAccount(bankAccountNumber);

			if (index < 0) {
				my::cout << "���� ������ ã�� ���߽��ϴ�." << my::endl;
				my::cout << "�ٽ� �޴��� ���ư��ϴ�." << my::endl << my::endl;
				break;
			}

			int money = 0;

			while (1) {
				my::cout << "��ݾ� : ";
				my::cin >> money;

				try {
					bank.Withdraw(index, money);
					
					my::cout << "��� �Ϸ�" << my::endl << my::endl;
					break;
				}
				catch (AccountException& expn) {
					expn.ShowExceptionReason();
				}
			}

			break;
		}
		case 4: {
			bank.ShowAccountsInfo();
			break;
		}

		case 5: {
			my::cout << "[���� ����]" << my::endl;

			int bankAccountNumber = 0;
			my::cout << "���¹�ȣ : ";
			my::cin >> bankAccountNumber;

			int index = bank.FindAccount(bankAccountNumber);

			if (index < 0) {
				my::cout << "���� ������ ã�� ���߽��ϴ�." << my::endl;
				my::cout << "�ٽ� �޴��� ���ư��ϴ�." << my::endl << my::endl;
				break;
			}

			bank.DeleteAccount(index);
			my::cout << "���� �Ϸ�" << my::endl << my::endl;

			break;
		}

		default:
			break;
		}

		if (menu == 6) break;
		if (1 > menu || menu > 6)  my::cout << "�߸��� ��ɾ� �Դϴ�." << my::endl << my::endl;
	}

	bank.releaseAccounts();

	return 0;
}