#include <iostream>
#include <cstdio>


typedef struct {
	int bankAccountNumber;
	char name[50];
	int balance;
} Account;

void PrintMenu() {
	std::cout << "==Menu==" << std::endl;
	std::cout << "1. 계좌개설" << std::endl;
	std::cout << "2. 입 금" << std::endl;
	std::cout << "3. 출 금" << std::endl;
	std::cout << "4. 계좌정보 전체 출력" << std::endl;
	std::cout << "5. 프로그램 종료" << std::endl;
}

void MakeAccount(Account &newAccount) {
	std::cout << "[계좌개설]" << std::endl;
	std::cout << "계좌번호 : ";
	std::cin >> newAccount.bankAccountNumber;
	std::cout << "이름 : ";
	std::cin >> newAccount.name;
	std::cout << "입금액 : ";
	std::cin >> newAccount.balance;
	std::cout << std::endl;
}

int FindAccount(Account accountData[], int accountDataMax, int bankAccountNumber) {
	for (int i = 0; i < accountDataMax; i++) {
		if (accountData[i].bankAccountNumber == bankAccountNumber) {
			return i;
		}
	}
	return -1;
}

void DepositAndWithdrawal(Account accountData[], int accountDataMax, int sign) {
	const char * signMenu = (sign > 0) ? "입금" : "출금";

	std::cout << "[" << signMenu << "]" << std::endl;

	int bankAccountNumber = 0, index = -1;
	while (1) {
		std::cout << "계좌번호 : ";
		std::cin >> bankAccountNumber;

		if (bankAccountNumber == 0) return;

		index = FindAccount(accountData, accountDataMax, bankAccountNumber);

		if (index < 0) {
			std::cout << "계좌 정보를 찾지 못했습니다." << std::endl << std::endl;
			std::cout << "다시 메뉴를 보고 싶으면 0을 입력해 주세요." << std::endl << std::endl;
		}
		else {
			break;
		}
	}

	int money = 0;
	std::cout << signMenu << "액 : ";
	std::cin >> money;
	accountData[index].balance += money * sign;

	std::cout << signMenu << "완료" << std::endl << std::endl;
	std::cout << std::endl;
}

void ShowAccountInfo(Account accountData[], int accountDataMax) {
	for (int i = 0; i < accountDataMax; i++) {
		std::cout << "계좌번호 : " << accountData[i].bankAccountNumber << std::endl;
		std::cout << "이 름 : " << accountData[i].name << std::endl;
		std::cout << "잔 액 : " << accountData[i].balance << std::endl;
		std::cout << std::endl;
	}
}

int GetAccountFile(Account accountData[], int &accountDataMax) {
	FILE* stream;
	errno_t err = fopen_s(&stream, "bank.txt", "rt");
	if (err != 0)
	{
		return -1;
	}

	fread(&accountDataMax, sizeof(accountDataMax), 1, stream);
	fread(accountData, sizeof(*accountData), accountDataMax, stream);

	fclose(stream);
	return 0;
}

int SaveAccountFile(Account accountData[], int &accountDataMax) {
	FILE* stream;
	errno_t err = fopen_s(&stream, "bank.txt", "wb");
	if (err != 0)
	{
		puts("파일 오픈 실패!");
		return -1;
	}

	fwrite(&accountDataMax, sizeof(accountDataMax), 1, stream);
	fwrite(accountData, sizeof(*accountData), accountDataMax, stream);

	fclose(stream);
	return 0;
}

int main(void) {
	Account accountData[50] = { 0 };
	int accountDataMax = 0;
	if (GetAccountFile(accountData, accountDataMax) != 0) {
		std::cout << "파일 오픈 실패! 프로그램을 종료합니다." << std::endl;
		return 0;
	}

	int menu = 0;
	while (1) {
		PrintMenu();

		std::cout << "선택 : ";
		std::cin >> menu;
		std::cout << std::endl;

		switch (menu)
		{
		case 1: {
			MakeAccount(accountData[accountDataMax]);
			accountDataMax++;
			break;
		}
		case 2: {
			DepositAndWithdrawal(accountData, accountDataMax, 1);
			break;
		}
		case 3: {
			DepositAndWithdrawal(accountData, accountDataMax, -1);
			break;
		}
		case 4: {
			ShowAccountInfo(accountData, accountDataMax);
		}

		default:
			break;
		}

		if (menu == 5) break;
		if (1 > menu || menu > 5)  std::cout << "잘못된 명령어 입니다." << std::endl << std::endl;
	}

	if (SaveAccountFile(accountData, accountDataMax) != 0) {
		std::cout << "파일 저장 실패!" << std::endl;
	}

	return 0;
}