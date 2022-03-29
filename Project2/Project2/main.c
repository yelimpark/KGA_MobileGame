#include <stdio.h>

int StrLen(char* str) {
	int idx = 0;
	while (str[idx] != '\0')
	{
		idx++;
	}
	return idx;
}

int IsNumber(char* str) {
	int res = 1;
	int len = StrLen(str);
	if (len == 4 || len == 6) {
		for (int i = 0; i < len; i++) {
			if (48 > str[i] || str[i] > 57) {
				res = 0;
				break;
			}
		}
	}
	else res = 0;

	return res;
}

int StrToInt(char* str) {
	int len = StrLen(str);
	int num = 0;

	for (int i = 0; i < len; i++) {
		if (str[i] == '-' || str[i] == '+') {
			continue;
		}
		num += str[i] - '0';
		num *= (i == len - 1) ? 1 : 10;
	}

	if (str[0] == '-') {
		num *= (-1);
	}

	return num;
}

//문제 13-1
//문제 1
void P1(void) {
	int arr[5] = { 1,2,3,4,5 };
	int len = sizeof(arr) / sizeof(int);
	int* ptr = &arr[0];

	for (int i = 0; i < len; i++) {
		*ptr += 2;
		printf("%d ", *ptr);
		ptr++;
	}
}

//문제 2
void P2(void) {
	int arr[5] = { 1,2,3,4,5 };
	int len = sizeof(arr) / sizeof(int);
	int* ptr = &arr[0];

	for (int i = 0; i < len; i++) {
		*(ptr + i) += 2;
		printf("%d ", *(ptr + i));
	}
}

//문제 3
void P3(void) {
	int arr[5] = { 1,2,3,4,5 };
	int len = sizeof(arr) / sizeof(int);
	int* ptr = &arr[len-1];

	int sum = 0;
	for (int i = 0; i < len; i++) {
		sum += *ptr;
		ptr--;
	}

	printf("%d \n", sum);
}

//문제 4
void P4(void) {
	int arr[6] = { 1,2,3,4,5,6 };
	int len = sizeof(arr) / sizeof(int);
	int* ptr1 = &arr[0];
	int * ptr2 = &arr[len - 1];

	for (int i = 0; i < len/2 ; i++) {
		int tmp = *(ptr1+i);
		*(ptr1+i) = *(ptr2-i);
		*(ptr2-i) = tmp;
	}

	for (int i = 0; i < len; i++) {
		printf("%d ", *(ptr1 + i));
	}
}

//문제 14-1
//문제 1
int SquareByValue(int num) {
	return num * num;
}

void SquareByReference(int * num) {
	*num *= *num;
}

//문제 2
void Swap3(int* num1, int* num2, int* num3) {
	int tmp = *num1;
	*num1 = *num3;
	*num3 = *num2;
	*num2 = tmp;
}

//도전
//문제 1
void Even() {
	printf("총 10개의 숫자 입력\n");

	int arr[10] = { 0 };
	int len = (int)sizeof(arr) / (int)sizeof(int);
	for (int i = 0; i < len; i++) {
		printf("입력: ");
		scanf_s("%d", &arr[i]);
	}

	printf("홀수 출력: ");
	for (int i = 0; i < 10; i++) {
		if (arr[i] % 2 != 0) printf("%d ", arr[i]);
	}

	printf("\n");

	printf("짝수 출력: ");
	for (int i = 0; i < 10; i++) {
		if (arr[i] % 2 == 0) printf("%d ", arr[i]);
	}
}

//문제 2
void Binary() {
	int num = 0;
	printf("10진수 정수 입력: ");
	scanf_s("%d", &num);

	int binary = (num % 2 == 0) ? 1 : 0;
	int isEven = (num % 2 == 0) ? 1 : 0;

	while (num / 2 > 0) {
		binary += (num % 2);
		binary *= 10;
		num /= 2;
	}
	binary += num % 2;

	if (isEven) {
		binary --;
	}

	printf("%d\n", binary);
}

//문제 3
void Even2() {
	printf("총 10개의 숫자 입력\n");

	int arr[10] = { 0 };
	int len = (int)sizeof(arr) / (int)sizeof(int);
	
	int num = 0;
	int count = 0;
	for (int i = 0; i < len; i++) {
		printf("입력: ");
		scanf_s("%d", &num);
		if (num % 2 == 0) {
			count++;
			arr[len -count] = num;
		}
		else {
			arr[i-count] = num;
		}
	}

	printf("배열 요소의 출력: ");
	for (int j = 0; j < len; j++) {
		printf("%d ", arr[j]);
	}
}

//문제 4
int Palindrone(char* str, int len) {
	for (int i = 0; i < len/2; i++) {
		if (str[i] != str[len - 1 - i])
			return 0;
	}
	return 1;
}

//문제 5
void DesSort(int arr[], int len) {
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < (len - i) - 1; j++) {
			if (arr[j] < arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
int main(void) {

	//char str[50];
	//printf("enter the sentence : ");
	//scanf_s("%s", str, (int)sizeof(str) / (int)sizeof(char));
	//if (IsNumber(str)) printf("True\n");
	//else printf("False\n");

	//char str[6];
	//printf("enter the sentence : ");
	//scanf_s("%s", str, (int)sizeof(str) / (int)sizeof(char));
	//printf("%d \n", StrToInt(str));

	//P1();
	//P2();
	//P3();
	//P4();

	//printf("%d\n", SquareByValue(3));
	//int num = 3;
	//SquareByReference(&num);
	//printf("%d\n", num);

	//int num1 = 1, num2 = 2, num3 = 3;
	//printf("%d %d %d\n", num1, num2, num3);
	//Swap3(&num1, &num2, &num3);
	//printf("%d %d %d\n", num1, num2, num3);

	//Even();
	//Binary();
	//Even2();

	//char str[50];
	//printf("enter the sentence : ");
	//scanf_s("%s", str, (int)sizeof(str) / (int)sizeof(char));
	//int len = StrLen(str);
	//printf("%d", Palindrone(str, len));

	//int arr[7] = { 0 };
	//int len = (int)sizeof(arr) / (int)sizeof(int);
	//for (int i = 0; i < len; i++) {
	//	printf("입력: ");
	//	scanf_s("%d", &arr[i]);
	//}
	//DesSort(arr, len);

	//for (int j = 0; j < len; j++) {
	//	printf("%d ", arr[j]);
	//}


	return 0;
}