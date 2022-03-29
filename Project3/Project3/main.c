#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void BubbleSort(int ary[], int len, int (*ptr) (int, int));

int Accending(int lhs, int rhs) {
	return (lhs > rhs);
};	// 오름차순
int Deccending(int lhs, int rhs) {
	return (lhs < rhs);
};	// 내람차순

//도전 3
// 1

void TurnSquare(int arr[][4]) {
	int res[4][4] = { 0 };

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			res[j][3 - i] = arr[i][j];
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d ", res[i][j]);
			arr[i][j] = res[i][j];
		}
		printf("\n");
	}
}

// 2
void Snail() {
	int arr[5][5] = { 0 };
	int size = 5;

	int i = 0, j = -1, count = size;
	int turn = 1;
	while (1) {
		if (i == size / 2 && j == size / 2) break;
		if (turn) {
			for (int k = 0; k < count; k++) {
				j++;
				scanf_s("%d", &arr[i][j]);
			}
			count--;
			for (int k = 0; k < count; k++) {
				i++;
				scanf_s("%d", &arr[i][j]);
			}
		}
		else {
			for (int k = 0; k < count; k++) {
				j--;
				scanf_s("%d", &arr[i][j]);
			}
			count--;
			for (int k = 0; k < count; k++) {
				i--;
				scanf_s("%d", &arr[i][j]);
			}
		}
		turn = (turn)? 0 : 1;
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
 }

//3
void Rand99() {
	printf("난수의 범위: 0부터 99 까지 \n");
	for (int i = 0; i < 5; i++) {
		printf("난수 출력: %d \n", rand()%100);
	}
}

//4
void dice() {
	srand((int)time(NULL));
	for (int i = 0; i < 2; i++)
		printf("주사위 %d의 결과 : %d \n", i, rand()%6+1);

}

//5
void RSP() {
	int win = 0;
	int duse = 0;
	while (1) {
		printf("바위는 1, 가위는 2, 보는 3:");
		int player = 0;
		scanf_s("%d", &player);
		int computer = rand() % 3 + 1;

		if (player == computer) {
			printf("당신 : %d, 컴퓨터 : %d, 비겼습니다.\n", player, computer);
			duse++;
		}
		else if (player == 1 && computer == 2) {
			printf("당신 : %d, 컴퓨터 : %d, 이겼습니다.\n", player, computer);
			win++;
		}
		else if (player == 2 && computer == 3) {
			printf("당신 : %d, 컴퓨터 : %d, 이겼습니다.\n", player, computer);
			win++;
		}
		else if (player == 3 && computer == 1) {
			printf("당신 : %d, 컴퓨터 : %d, 이겼습니다.\n", player, computer);
			win++;
		}
		else {
			printf("당신 : %d, 컴퓨터 : %d, 졌습니다.\n", player, computer);
			break;
		}
	}
	printf("\n게임의 결과 : %d승 %d무\n", win, duse);
}

int main(void)
{
	//int arr[4] = { 3, 2, 1, 4 };
	//int length = sizeof(arr) / sizeof(int);

	//BubbleSort(arr, length, Accending);
	//for (int i = 0; i < 4; i++)
	//{
	//	printf("%d ", arr[i]); // 1, 2, 3, 4
	//}
	//printf("\n");


	//BubbleSort(arr, length, Deccending);
	//for (int i = 0; i < 4; i++)
	//{
	//	printf("%d ", arr[i]); // 4, 3, 2, 1
	//}
	//printf("\n");

	//도전 3

	//int arr[4][4] = {
	//{1,2,3,4},
	//{5,6,7,8},
	//{9,10,11,12},
	//{13,14,15,16}
	//};
	//for (int i = 0; i < 3; i++) {
	//	TurnSquare(arr);
	//}

	// 도전 3-3
	//Rand99();

	//도전 3-4
	//dice();

	//도전 3-5
	//RSP();

	//도전 3-6
	//srand((int)time(NULL));
	//int arr[3] = { rand() % 10, rand() % 10, rand() % 10 };
	//int input[3] = { 0 };
	//
	//int count = 0;
	//while (1) {
	//	int strike = 0, ball = 0;
	//	scanf_s("%d %d %d", &input[0], &input[1], &input[2]);
	//	
	//	for (int i = 0; i < 3; i++) {
	//		for (int j = 0; j < 3; j++) {
	//			if (arr[i] == input[j] && i == j) {
	//				strike++;
	//				break;
	//			}
	//			else if (arr[i] == input[j]) {
	//				ball++;
	//				break;
	//			}
	//		}
	//	}
	//	count++;
	//	printf("%d 번째 도전 결과 : %d strike, %d ball!\n", count, strike, ball);
	//	if (strike == 3) {
	//		printf("Game Over!\n");
	//		break;
	//	}
	//}

	//Snail();

	return 0;
}

void BubbleSort(int ary[], int len, int (*ptr) (int, int) )
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < (len - i) - 1; j++)
		{
			if (ptr(ary[j], ary[j+1]))
			{
				int temp = ary[j];
				ary[j] = ary[j + 1];
				ary[j + 1] = temp;
			}
		}
	}
}