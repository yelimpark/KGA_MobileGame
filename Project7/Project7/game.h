#pragma once

typedef struct gamedata {
	int alpabet;
	int chance;
} GD;

void init(GD* _gd);

void start();

int play(GD _gd);

int IsCorrect(int keyGet, int alpabet);

void Win();

void Loose(GD _gd);