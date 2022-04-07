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
			std::cout << "[계좌종류선택]" << std::endl;
			std::cout << "1. 보통예금계좌" << std::endl;
			std::cout << "2. 신용신뢰계좌" << std::endl;

			int accountType = 0;
			std::cout << "선택: ";
			std::cin >> accountType;
			std::cout << std::endl;

			if (accountType < 1 || 2 < accountType) {
				std::cout << "잘못된 명령어 입니다." << std::endl << std::endl;
				break;
			}

			int bankAccountNumber = 0;
			char name[100] = " ";
			int balance = 0;
			int interest = 0;

			if (accountType == 1) {
				std::cout << "[보통예금계좌개설]" << std::endl;

			}
			else if (accountType == 2) {
				std::cout << "[신용신뢰계좌개설]" << std::endl;
			}

			std::cout << "계좌번호 : ";
			std::cin >> bankAccountNumber;
			std::cout << "이름 : ";
			std::cin >> name;
			std::cout << "입금액 : ";
			std::cin >> balance;
			std::cout << "이자율 : ";
			std::cin >> interest;
			
			if (accountType == 1) {
				std::cout << std::endl;
				bank.MakeAccount(bankAccountNumber, name, balance, interest);
			}
			else if (accountType == 2) {
				int cradit = 0;
				std::cout << "신용등급(1toA, 2toB, 3toC) : ";
				std::cin >> cradit;
				std::cout << std::endl;
				bank.MakeAccount(bankAccountNumber, name, balance, interest, cradit);
			}

			break;
		}
		case 2: {
			std::cout << "[입 금]" << std::endl;

			int bankAccountNumber = 0;
			std::cout << "계좌번호 : ";
			std::cin >> bankAccountNumber;

			int index = bank.FindAccount(bankAccountNumber);

			if (index < 0) {
				std::cout << "계좌 정보를 찾지 못했습니다." << std::endl;
				std::cout << "다시 메뉴로 돌아갑니다." << std::endl << std::endl;
				break;
			}

			int money = 0;
			std::cout << "입금액 : ";
			std::cin >> money;

			bank.Deposit(index, money);

			std::cout << "입금 완료" << std::endl << std::endl;
			
			break;
		}
		case 3: {
			std::cout << "[출 금]" << std::endl;

			int bankAccountNumber = 0;
			std::cout << "계좌번호 : ";
			std::cin >> bankAccountNumber;

			int index = bank.FindAccount(bankAccountNumber);

			if (index < 0) {
				std::cout << "계좌 정보를 찾지 못했습니다." << std::endl;
				std::cout << "다시 메뉴로 돌아갑니다." << std::endl << std::endl;
				break;
			}

			int money = 0;
			std::cout << "출금액 : ";
			std::cin >> money;

			bank.Withdraw(index, money);

			std::cout << "출금 완료" << std::endl << std::endl;

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