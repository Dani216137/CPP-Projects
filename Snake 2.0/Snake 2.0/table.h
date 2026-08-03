#pragma once
#include "worm.h"

extern const char WALL;
extern const char ESPACE;
extern const char UDOWN;
extern const char SNAKE;
extern const char FRUIT;
extern bool game;
extern bool exist;
extern  char Map[20][20];

extern int Score;

void DrawMap(const Snake& snake) ;
void GenerateFruits();

