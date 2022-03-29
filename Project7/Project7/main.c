#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"

int main() {

	GD myGame;
	init(&myGame);

	start();
	if (play(myGame)) {
		Win();
	}
	else {
		Loose(myGame);
	}

	return 0;
}

/*
작은 과제 1
A~Z중 컴퓨터가 임의의 키 하나를 선택하고
프레이어는 키를 3번 입력해서 3번 안에 컴퓨터가 생각하는 키를
맞추는 게임

출력화면 예시) A~Z중 키 하나를 누르세요.
*/