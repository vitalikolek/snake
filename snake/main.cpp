#include "SnakeLogic.h"

int main() {
	srand(time(0));

	SnakeLogic* snake = new SnakeLogic();

	snake->showSnake();
}