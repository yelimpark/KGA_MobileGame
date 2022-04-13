#include <cstdio>
#include "AccountHandler.h"
#include "WithdrawException.h"
#include "WrongMoney.h"

int main(void) {
	AccountHandler bank;

	int menu = 0;
	while (1) {
		my::cout << "==Menu==" << my::endl;
		my::cout << "1. 계좌개설" << my::endl;
		my::cout << "2. 입 금" << my::endl;
		my::cout << "3. 출 금" << my::endl;
		my::cout << "4. 계좌정보 전체 출력" << my::endl;
		my::cout << "5. 계좌 삭제" << my::endl;
		my::cout << "6. 프로그램 종료" << my::endl;

		my::cout << "선택 : ";
		my::cin >> menu;
		my::cout << my::endl;

		switch (menu)
		{
		case 1: {
			my::cout << "[계좌종류선택]" << my::endl;
			my::cout << "1. 보통예금계좌" << my::endl;
			my::cout << "2. 신용신뢰계좌" << my::endl;

			int accountType = 0;
			my::cout << "선택: ";
			my::cin >> accountType;
			my::cout << my::endl;

			if (accountType < 1 || 2 < accountType) {
				my::cout << "잘못된 명령어 입니다." << my::endl << my::endl;
				my::cout << "다시 메뉴로 돌아갑니다." << my::endl << my::endl;
				break;
			}

			int bankAccountNumber = 0;
			char name[100] = " ";
			int balance = 0;
			int interest = 0;

			if (accountType == 1) {
				my::cout << "[보통예금계좌개설]" << my::endl;

			}
			else if (accountType == 2) {
				my::cout << "[신용신뢰계좌개설]" << my::endl;
			}

			my::cout << "계좌번호 : ";
			my::cin >> bankAccountNumber;
			my::cout << "이름 : ";
			my::cin >> name;
			my::cout << "입금액 : ";
			my::cin >> balance;
			my::cout << "이자율 : ";
			my::cin >> interest;
			
			if (accountType == 1) {
				my::cout << my::endl;
				bank.MakeAccount(bankAccountNumber, name, balance, interest);
			}
			else if (accountType == 2) {
				int cradit = 0;
				my::cout << "신용등급(1toA, 2toB, 3toC) : ";
				my::cin >> cradit;
				my::cout << my::endl;
				bank.MakeAccount(bankAccountNumber, name, balance, interest, cradit);
			}

			break;
		}
		case 2: {
			my::cout << "[입 금]" << my::endl;

			int bankAccountNumber = 0;
			my::cout << "계좌번호 : ";
			my::cin >> bankAccountNumber;

			int index = bank.FindAccount(bankAccountNumber);

			if (index < 0) {
				my::cout << "계좌 정보를 찾지 못했습니다." << my::endl;
				my::cout << "다시 메뉴로 돌아갑니다." << my::endl << my::endl;
				break;
			}

			int money = 0;
			
			while (1) {
				my::cout << "입금액 : ";
				my::cin >> money;

				try {
					bank.Deposit(index, money);

					my::cout << "입금 완료" << my::endl << my::endl;
					break;
				}
				catch (AccountException& expn) {
					expn.ShowExceptionReason();
				}
			}
			
			break;
		}
		case 3: {
			my::cout << "[출 금]" << my::endl;

			int bankAccountNumber = 0;
			my::cout << "계좌번호 : ";
			my::cin >> bankAccountNumber;

			int index = bank.FindAccount(bankAccountNumber);

			if (index < 0) {
				my::cout << "계좌 정보를 찾지 못했습니다." << my::endl;
				my::cout << "다시 메뉴로 돌아갑니다." << my::endl << my::endl;
				break;
			}

			int money = 0;

			while (1) {
				my::cout << "출금액 : ";
				my::cin >> money;

				try {
					bank.Withdraw(index, money);
					
					my::cout << "출금 완료" << my::endl << my::endl;
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
			my::cout << "[계좌 삭제]" << my::endl;

			int bankAccountNumber = 0;
			my::cout << "계좌번호 : ";
			my::cin >> bankAccountNumber;

			int index = bank.FindAccount(bankAccountNumber);

			if (index < 0) {
				my::cout << "계좌 정보를 찾지 못했습니다." << my::endl;
				my::cout << "다시 메뉴로 돌아갑니다." << my::endl << my::endl;
				break;
			}

			bank.DeleteAccount(index);
			my::cout << "삭제 완료" << my::endl << my::endl;

			break;
		}

		default:
			break;
		}

		if (menu == 6) break;
		if (1 > menu || menu > 6)  my::cout << "잘못된 명령어 입니다." << my::endl << my::endl;
	}

	bank.releaseAccounts();

	return 0;
}