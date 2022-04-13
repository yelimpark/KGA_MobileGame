#include <iostream>

int StoI(char* str) {
	int len = strlen(str);
	int num = 0;
	
	for (int i = 0; i < len; ++i) {
		if (str[i] < '0' || str[i] > '9')
			throw str[i];
		num += (int)(pow((double)10, (len - 1) - i) * (str[i] + (7 - '7')));
	}
	return num;
}

int main(void) {
	char str1[100];
	char str2[100];

	while (1) {
		std::cout << "�� ���� ���� �Է� : ";
		std::cin >> str1 >> str2;

		try {
			std::cout << str1 << " + " << str2 << " = "
				<< StoI(str1) + StoI(str2) << std::endl;

			break;
		}
		catch (char ch) {
			std::cout << "���� " << ch << "�� �ԷµǾ����ϴ�." << std::endl;
		}
	}

	std::cout << "end of main" << std::endl;
	return 0;
}