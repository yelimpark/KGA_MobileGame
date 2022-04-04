#include <iostream>
#include <cstdio>


typedef struct {
	int bankAccountNumber;
	char name[50];
	int balance;
} Account;

void PrintMenu() {
	std::cout << "==Menu==" << std::endl;
	std::cout << "1. ���°���" << std::endl;
	std::cout << "2. �� ��" << std::endl;
	std::cout << "3. �� ��" << std::endl;
	std::cout << "4. �������� ��ü ���" << std::endl;
	std::cout << "5. ���α׷� ����" << std::endl;
}

void MakeAccount(Account &newAccount) {
	std::cout << "[���°���]" << std::endl;
	std::cout << "���¹�ȣ : ";
	std::cin >> newAccount.bankAccountNumber;
	std::cout << "�̸� : ";
	std::cin >> newAccount.name;
	std::cout << "�Աݾ� : ";
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
	const char * signMenu = (sign > 0) ? "�Ա�" : "���";

	std::cout << "[" << signMenu << "]" << std::endl;

	int bankAccountNumber = 0, index = -1;
	while (1) {
		std::cout << "���¹�ȣ : ";
		std::cin >> bankAccountNumber;

		if (bankAccountNumber == 0) return;

		index = FindAccount(accountData, accountDataMax, bankAccountNumber);

		if (index < 0) {
			std::cout << "���� ������ ã�� ���߽��ϴ�." << std::endl << std::endl;
			std::cout << "�ٽ� �޴��� ���� ������ 0�� �Է��� �ּ���." << std::endl << std::endl;
		}
		else {
			break;
		}
	}

	int money = 0;
	std::cout << signMenu << "�� : ";
	std::cin >> money;
	accountData[index].balance += money * sign;

	std::cout << signMenu << "�Ϸ�" << std::endl << std::endl;
	std::cout << std::endl;
}

void ShowAccountInfo(Account accountData[], int accountDataMax) {
	for (int i = 0; i < accountDataMax; i++) {
		std::cout << "���¹�ȣ : " << accountData[i].bankAccountNumber << std::endl;
		std::cout << "�� �� : " << accountData[i].name << std::endl;
		std::cout << "�� �� : " << accountData[i].balance << std::endl;
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
		puts("���� ���� ����!");
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
		std::cout << "���� ���� ����! ���α׷��� �����մϴ�." << std::endl;
		return 0;
	}

	int menu = 0;
	while (1) {
		PrintMenu();

		std::cout << "���� : ";
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
		if (1 > menu || menu > 5)  std::cout << "�߸��� ��ɾ� �Դϴ�." << std::endl << std::endl;
	}

	if (SaveAccountFile(accountData, accountDataMax) != 0) {
		std::cout << "���� ���� ����!" << std::endl;
	}

	return 0;
}