#include <stdio.h>
#include <string.h>

//문제 1
int PlusStrNum(char * ch) {
	int len = strlen(ch);
	int sum = 0;
	for (int i = 0; i < len; i++) {
		if ('0' < ch[i] && ch[i] <= '9') {
			sum += ch[i] - '0';
		}
	}
	return sum;
}

//문제 3
void DevideNameAge(char * str, char * name, char * age) {
	int len = strlen(str);
	int flag = 1;
	int j = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == ' ') {
			flag = 0;
			name[i] = 0;
			continue;
		}

		if (flag) {
			name[i] = str[i];
		}
		else {
			age[j] = str[i];
			j++;
		}
	}
	age[j] = 0;
}

int IsSpace(char c) {
	if (c == ' ' || c == '\t') return 1;
	return 0;
}

void DevideNameAge2(char* str, char* name, char* age) {
	int len = strlen(str);
	int flag = 1;
	int j = 0;
	int k = 0;
	for (int i = 0; i < len; i++) {
		if (IsSpace(str[i]) && ('0' < str[i + 1] && str[i + 1] <= '9')) {
			flag = 0;
			name[k] = 0;
			continue;
		}
		else if (IsSpace(name[k-1]) && IsSpace(str[i])) {
			continue;
		}

		if (flag) {
			if ('A' <= str[i] && str[i] <= 'Z') {
				name[k] = str[i] + ('a' - 'A');
			}
			else {
				name[k] = str[i];
			}
			k++;
		}
		else {
			age[j] = str[i];
			j++;
		}
	}
	age[j] = 0;
}

//void IsSamePerson(char* str1, char* str2) {
//	int max = (strlen(str1) > strlen(str2)) ? strlen(str1) : strlen(str2);
//	int isSmaeName = 1;
//	int isSameAge = 1;
//
//	for (int i = 0; i < max; i++) {
//		if ('0' < str1[i] && str1[i] <= '9') {
//
//		}
//		if (str1[i] != str2[i]) {
//			isSmaeName = 0;
//		}
//	}
//}

int main1() {
	//문제 1
	char ch[100] = "0";
	gets(ch);
	printf("%d \n", PlusStrNum(ch));

	//문제 2
	char str1[20];
	char str2[20];
	char str3[40];

	fgets(str1, sizeof(str1), stdin);
	fgets(str2, sizeof(str2), stdin);

	int len = strlen(str1);
	str1[len - 1] = 0;
	str1[len - 1] = 0;
	strcpy_s(str3, sizeof(str3), str1);
	strcat_s(str3, sizeof(str2), str2);
	puts(str3);

	//문제 3
	char input1[100] = "0";
	char input2[100] = "0";
	fgets(input1, sizeof(input1), stdin);
	fgets(input2, sizeof(input2), stdin);

	char name1[100], age1[100];
	char name2[100], age2[100];

	DevideNameAge2(input1, name1, age1);
	DevideNameAge2(input2, name2, age2);

	if (strcmp(name1, name2) == 0)
		printf("같은 이름, ");
	else
		printf("다른 이름, ");

	if (strcmp(age1, age2) == 0)
		printf("같은 나이. \n");
	else
		printf("다른 나이. \n");

	return 0;
}