#pragma once
#include "GameLogic.h"
#include <conio.h>

class SnakeLogic : public GameLogic
{
private:
	
protected:
	enum eDirection { STOP = 0, LEFT = 1, RIGHT = 2, UP = 3, DOWN = 4};
	eDirection dir = STOP;
public:
	SnakeLogic();
	void checking(eDirection first, eDirection second);
	void input();
	void logic();
	void FruitSpawnBody();
	void showSnake();
	~SnakeLogic();
};

