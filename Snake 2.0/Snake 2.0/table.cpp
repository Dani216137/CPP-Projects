#include <iostream>
#include "table.h"
#include "worm.h"
#include <random>

const char WALL = '|';
const char ESPACE = ' ';
const char UDOWN = '-';
const char SNAKE = 'O';
const char FRUIT = '*';

bool game = true;
bool exist = false;

char Map[20][20];

int Score = 0;

void DrawMap(const Snake& snake) {
	
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 20; ++j) {
			if (i == 0 || i == 19) {
				Map[i][j] = UDOWN;
			}
			else if (j == 0 || j == 19) {
				Map[i][j] = WALL;
			}
			else if(Map[i][j] != FRUIT)
				Map[i][j] = ESPACE;
		}
	}
	const auto& body=snake.GetBody();

	for (const auto& x : body) {

		Map[x.x][x.y] = SNAKE;
	}

	GenerateFruits();

	std::cout << "Score:" << Score;
	std::cout << '\t' << '\n';

	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 20; ++j) {
			std::cout << Map[i][j] << ' ';
		}
		std::cout << '\n';
	}
}

void GenerateFruits() {

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dis(1, 18);
    int num1 = dis(gen);
    int num2 = dis(gen);


    if (!exist) {

        if (Map[num1][num2] != WALL && Map[num1][num2] != UDOWN && Map[num1][num2] != SNAKE) {
            Map[num1][num2] = FRUIT;
            exist = true;
        }
        else
            GenerateFruits();
    }

}


