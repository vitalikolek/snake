#pragma once
#include <iostream>
#include <time.h>
#include "windows.h"

using namespace std;

class GameLogic {
protected:
	int height = 15;
	int width = 15;
	int score = 1;
	int snakeSpeed = 0;
	int snakeX = this->width / 2;
	int snakeY = this->height / 2;
	int fruitX = 1 + rand() % (this->width - 2);
	int fruitY = 1 + rand() % (this->height - 2);
	int tailX[225], tailY[225];
	int nTail = 0;
	bool gameOver = false;
public:
	GameLogic();
	void setUp();
	void draw();
	~GameLogic();
};