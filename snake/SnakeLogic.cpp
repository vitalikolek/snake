#include "SnakeLogic.h";
#include "GameLogic.h"

SnakeLogic::SnakeLogic() {
}

void SnakeLogic::checking(eDirection first, eDirection second) {
    if (this->dir == first) {
    }
    else {
        this->dir = second;
    }
}

void SnakeLogic::input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            checking(RIGHT, LEFT);
            break;
        case 'd':
            checking(LEFT, RIGHT);
            break;
        case 'w':
            checking(DOWN, UP);
            break;
        case 's':
            checking(UP, DOWN);
            break;
        case 'x':
            this->gameOver = true;
            break;
        }
    }
}

void SnakeLogic::logic() {
    int prevX = this->tailX[0];
    int prevY = this->tailY[0];
    int prevTwoX, prevTwoY;
    this->tailX[0] = this->snakeX;
    this->tailY[0] = this->snakeY;
    for (int i = 1; i < this->nTail; i++) {
        prevTwoX = this->tailX[i];
        prevTwoY = this->tailY[i];
        this->tailX[i] = prevX;
        this->tailY[i] = prevY;
        prevX = prevTwoX;
        prevY = prevTwoY;
    }

    switch (this->dir) {
    case LEFT:
        this->snakeY--;
        break;
    case RIGHT:
        this->snakeY++;
        break;
    case UP:
        this->snakeX--;
        break;
    case DOWN:
        this->snakeX++;
        break;
    }

    if (this->snakeX > this->width - 1 || this->snakeX < 0 || this->snakeY > this->height - 2 || this->snakeY < 1) {
        this->gameOver = true;
    }

    if (this->snakeX == this->fruitX && this->snakeY == this->fruitY) {
        score++;
        this->fruitX = 1 + rand() % (this->width - 2);
        this->fruitY = 1 + rand() % (this->height - 2);
        nTail++;
    }
}

void SnakeLogic::FruitSpawnBody() { 
    for (int i = 0; i < this->nTail; i++) {
        if (tailX[i] == fruitX && tailY[i] == fruitY) {
            this->fruitX = 0;
            this->fruitY = 0;
            this->fruitX = 1 + rand() % (this->width - 2);
            this->fruitY = 1 + rand() % (this->height - 2);
        }
    }
}// if fruit spawn in the body

void SnakeLogic::showSnake() {
    while (this->gameOver != true) {
        system("cls");
        draw();
        input();
        logic();
        FruitSpawnBody();
        Sleep(175);
    }
}

SnakeLogic::~SnakeLogic() {
};