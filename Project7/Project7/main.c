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
���� ���� 1
A~Z�� ��ǻ�Ͱ� ������ Ű �ϳ��� �����ϰ�
�����̾�� Ű�� 3�� �Է��ؼ� 3�� �ȿ� ��ǻ�Ͱ� �����ϴ� Ű��
���ߴ� ����

���ȭ�� ����) A~Z�� Ű �ϳ��� ��������.
*/