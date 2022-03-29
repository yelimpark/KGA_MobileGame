#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "game.h";

void init(GD* _gd) {
	srand((unsigned int)time(NULL));
	_gd->alpabet = rand() % 26;
	_gd->chance = 5;
}

void start() {
	puts("A~Z�� Ű �ϳ��� ��������.");
}

int play(GD _gd) {
	for (int i = 0; i < _gd.chance; i++) {
		char keyGet = _getch();
		printf("%c�� �����̽��ϴ�.\n", keyGet);
		if (IsCorrect(keyGet, _gd.alpabet)) {
			return 1;
		}
		printf("���� ��ȸ�� %d�� �Դϴ�.\n\n", _gd.chance - i - 1);
	}
	return 0;
}

int IsCorrect(int keyGet, int alpabet) {
	if (keyGet == alpabet + 'a' || keyGet == alpabet + 'A') {
		return 1;
	}

	if (keyGet < alpabet + 'A' ||
		('A' <= keyGet && keyGet < alpabet + 'a')) {
		puts("���� ������ ���ĺ��� �װͺ��� �ڿ� �ֽ��ϴ�.");
	}
	else {
		puts("���� ������ ���ĺ��� �װͺ��� �տ� �ֽ��ϴ�.");
	}
	return 0;
}

void Win() {
	puts("�����Դϴ�!");
}

void Loose(GD _gd) {
	puts("���� ����");
	printf("������ %c�Դϴ�.\n", _gd.alpabet + 'A');
}