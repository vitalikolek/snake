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
	int snakeX = this->width / 2;
	int snakeY = this->height / 2;
	int fruitX = 1 + rand() % (this->width - 2);
	int fruitY = 1 + rand() % (this->height - 2);
	int tailX[225], tailY[225];
	int nTail = 0;
	bool gameOver = false;
public:
	GameLogic() {
	}

	void draw() {
        for (int i = 0; i < this->width - 1; i++) {
            cout << "##";
        }
        cout << endl;

        for (int i = 0; i < this->width; i++) {
            for (int j = 0; j < this->height; j++) {
                if (j == 0 || j == this->height - 1) {
                    cout << "#";
                }
                else if (i == this->snakeX && j == this->snakeY) {
                    cout << "O" << " ";
                }
                else if (i == this->fruitX && j == this->fruitY) {
                    cout << "F" << " ";
                }
                else {
                    bool print = false;
                    for (int k = 0; k < this->nTail; k++) {
                        if (this->tailX[k] == i && this->tailY[k] == j) {
                            print = true;
                            cout << "0" << " ";
                        }//show body

                        if (this->snakeX == this->tailX[k] && this->snakeY == this->tailY[k]) {
                            this->gameOver = true;
                        }//collision with the body
                    }
                    if (print != true) {
                        cout << " " << " ";
                    }
                }
            }
            cout << endl;
        }

        for (int i = 0; i < this->width - 1; i++) {
            cout << "##";
        }
        cout << endl;

        cout << "score: " << this->score;
    } // draw arrea

    ~GameLogic() {
    }
};