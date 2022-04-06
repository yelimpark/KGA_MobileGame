#include "AccountHandler.h"
#include <iostream>

AccountHandler::AccountHandler()
	:accountArrMax(0)
{

}

void AccountHandler::MakeAccount()
{
	int bankAccountNumber;
	char name[100] = " ";
	int balance;

	std::cout << "[계좌개설]" << std::endl;
	std::cout << "계좌번호 : ";
	std::cin >> bankAccountNumber;
	std::cout << "이름 : ";
	std::cin >> name;
	std::cout << "입금액 : ";
	std::cin >> balance;
	std::cout << std::endl;

	accountArr[accountArrMax++] = new Account(bankAccountNumber, name, balance);
}

int AccountHandler::FindAccount(int bankAccountNumber)
{
	for (int i = 0; i < accountArrMax; i++) {
		if (accountArr[i] -> GetBankAccountNumber() == bankAccountNumber) {
			return i;
		}
	}
	return -1;
}

void AccountHandler::ShowAccountsInfo()
{
	for (int i = 0; i < accountArrMax; i++) {
		accountArr[0]->ShowAccountInfo();
	}
}

int AccountHandler::GetAccountFile()
{
	FILE* stream;
	errno_t err = fopen_s(&stream, "bank.txt", "rt");
	if (err != 0)
	{
		return -1;
	}

	fread(&accountArrMax, sizeof(accountArrMax), 1, stream);
	fread(accountArr, sizeof(*accountArr), accountArrMax, stream);

	fclose(stream);

	return 0;
}

int AccountHandler::SaveAccountFile()
{
	FILE* stream;
	errno_t err = fopen_s(&stream, "bank.txt", "wb");
	if (err != 0)
	{
		puts("파일 오픈 실패!");
		return -1;
	}

	fwrite(&accountArrMax, sizeof(accountArrMax), 1, stream);
	fwrite(accountArr, sizeof(*accountArr), accountArrMax, stream);

	fclose(stream);
	return 0;
}

void AccountHandler::DepositAndWithdrawal(int sign)
{
	const char* signMenu = (sign > 0) ? "입금" : "출금";

	std::cout << "[" << signMenu << "]" << std::endl;

	int bankAccountNumber = 0;
	std::cout << "계좌번호 : ";
	std::cin >> bankAccountNumber;

	int index = FindAccount(bankAccountNumber);

	if (index < 0) {
		std::cout << "계좌 정보를 찾지 못했습니다." << std::endl;
		std::cout << "다시 메뉴로 돌아갑니다." << std::endl << std::endl;
		return;
	}

	int money = 0;
	std::cout << signMenu << "액 : ";
	std::cin >> money;

	if (sign > 0) {
		if (accountArr[index]->Deposit(money) < 0) return;
	}
	else {
		if (accountArr[index]->Withdraw(money) < 0) return;
	}

	std::cout << signMenu << "완료" << std::endl << std::endl;
	std::cout << std::endl;
}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accountArrMax; i++) {
		delete accountArr[i];
	}
}

