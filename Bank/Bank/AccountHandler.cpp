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

	std::cout << "[���°���]" << std::endl;
	std::cout << "���¹�ȣ : ";
	std::cin >> bankAccountNumber;
	std::cout << "�̸� : ";
	std::cin >> name;
	std::cout << "�Աݾ� : ";
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
		puts("���� ���� ����!");
		return -1;
	}

	fwrite(&accountArrMax, sizeof(accountArrMax), 1, stream);
	fwrite(accountArr, sizeof(*accountArr), accountArrMax, stream);

	fclose(stream);
	return 0;
}

void AccountHandler::DepositAndWithdrawal(int sign)
{
	const char* signMenu = (sign > 0) ? "�Ա�" : "���";

	std::cout << "[" << signMenu << "]" << std::endl;

	int bankAccountNumber = 0;
	std::cout << "���¹�ȣ : ";
	std::cin >> bankAccountNumber;

	int index = FindAccount(bankAccountNumber);

	if (index < 0) {
		std::cout << "���� ������ ã�� ���߽��ϴ�." << std::endl;
		std::cout << "�ٽ� �޴��� ���ư��ϴ�." << std::endl << std::endl;
		return;
	}

	int money = 0;
	std::cout << signMenu << "�� : ";
	std::cin >> money;

	if (sign > 0) {
		if (accountArr[index]->Deposit(money) < 0) return;
	}
	else {
		if (accountArr[index]->Withdraw(money) < 0) return;
	}

	std::cout << signMenu << "�Ϸ�" << std::endl << std::endl;
	std::cout << std::endl;
}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accountArrMax; i++) {
		delete accountArr[i];
	}
}

