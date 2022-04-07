#include "AccountHandler.h"
#include <iostream>

AccountHandler::AccountHandler()
	:accountArrMax(0)
{
	memset(accountArr, 0, sizeof(accountArr));
}

void AccountHandler::MakeAccount(int bankAccountNumber, const char* name, int balance, int interest)
{
	if (FindAccount(bankAccountNumber) >= 0) {
		std::cout << "�ߺ��� ���¹�ȣ �Դϴ�." << std::endl << std::endl;
		return;
	}
	accountArr[accountArrMax++] = new NormalAccount(bankAccountNumber, name, balance, interest);
}

void AccountHandler::MakeAccount(int bankAccountNumber, const char* name, int balance, int interest, int cradit)
{
	if (FindAccount(bankAccountNumber) >= 0) {
		std::cout << "�ߺ��� ���¹�ȣ �Դϴ�." << std::endl << std::endl;
		return;
	}
	accountArr[accountArrMax++] = new HighCreditAccount(bankAccountNumber, name, balance, interest, cradit);
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
		accountArr[i]->ShowAccountInfo();
	}
}

int AccountHandler::GetAccountFile()
{
	//FILE* stream;
	//errno_t err = fopen_s(&stream, "bank.txt", "rt");
	//if (err != 0)
	//{
	//	return -1;
	//}

	//fread(&accountArrMax, sizeof(accountArrMax), 1, stream);
	//for (int i=0; i< accountArrMax; i++)
	//fread(accountArr, sizeof(Account), accountArrMax, stream);

	//fclose(stream);

	return 0;
}

int AccountHandler::SaveAccountFile()
{
	//FILE* stream;
	//errno_t err = fopen_s(&stream, "bank.txt", "wb");
	//if (err != 0)
	//{
	//	puts("���� ���� ����!");
	//	return -1;
	//}

	//fwrite(&accountArrMax, sizeof(accountArrMax), 1, stream);
	//fwrite(accountArr, sizeof(*accountArr), accountArrMax, stream);

	//fclose(stream);
	return 0;
}

int AccountHandler::Deposit(int index, int money)
{
	if (accountArr[index]->Deposit(money) < 0) return -1;
	return 0;
}

int AccountHandler::Withdraw(int index, int money)
{
	if (accountArr[index]->Withdraw(money) < 0) return -1;
	return 0;
}

//void AccountHandler::DepositAndWithdrawal(int sign)
//{
//	const char* signMenu = (sign > 0) ? "�Ա�" : "���";
//
//	std::cout << "[" << signMenu << "]" << std::endl;
//
//	int bankAccountNumber = 0;
//	std::cout << "���¹�ȣ : ";
//	std::cin >> bankAccountNumber;
//
//	int index = FindAccount(bankAccountNumber);
//
//	if (index < 0) {
//		std::cout << "���� ������ ã�� ���߽��ϴ�." << std::endl;
//		std::cout << "�ٽ� �޴��� ���ư��ϴ�." << std::endl << std::endl;
//		return;
//	}
//
//	int money = 0;
//	std::cout << signMenu << "�� : ";
//	std::cin >> money;
//
//	if (sign > 0) {
//		if (accountArr[index]->Deposit(money) < 0) return;
//	}
//	else {
//		if (accountArr[index]->Withdraw(money) < 0) return;
//	}
//
//	std::cout << signMenu << "�Ϸ�" << std::endl << std::endl;
//	std::cout << std::endl;
//}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accountArrMax; i++) {
		delete accountArr[i];
	}
}

