#include "GameLogic.h"
#include "SnakeLogic.h"

int main() {
	GameLogic* game = new GameLogic();
	SnakeLogic* snake = new SnakeLogic();

	game->setUp();
	snake->showSnake();
}