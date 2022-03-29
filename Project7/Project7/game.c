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
	puts("A~Z중 키 하나를 누르세요.");
}

int play(GD _gd) {
	for (int i = 0; i < _gd.chance; i++) {
		char keyGet = _getch();
		printf("%c를 누르셨습니다.\n", keyGet);
		if (IsCorrect(keyGet, _gd.alpabet)) {
			return 1;
		}
		printf("남은 기회는 %d번 입니다.\n\n", _gd.chance - i - 1);
	}
	return 0;
}

int IsCorrect(int keyGet, int alpabet) {
	if (keyGet == alpabet + 'a' || keyGet == alpabet + 'A') {
		return 1;
	}

	if (keyGet < alpabet + 'A' ||
		('A' <= keyGet && keyGet < alpabet + 'a')) {
		puts("제가 생각한 알파벳은 그것보다 뒤에 있습니다.");
	}
	else {
		puts("제가 생각한 알파벳은 그것보다 앞에 있습니다.");
	}
	return 0;
}

void Win() {
	puts("정답입니다!");
}

void Loose(GD _gd) {
	puts("게임 오버");
	printf("정답은 %c입니다.\n", _gd.alpabet + 'A');
}