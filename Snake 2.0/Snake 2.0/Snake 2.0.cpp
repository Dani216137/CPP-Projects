// Snake 2.0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "table.h"
#include "worm.h"
#include <filesystem>
#include <conio.h>
#include <Windows.h>
#include <deque>
#include "menues.h"




int main()
{

	while (true) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO cursorInfo;
		cursorInfo.dwSize = 100;
		cursorInfo.bVisible = FALSE;
		SetConsoleCursorInfo(hConsole, &cursorInfo);
		Snake s;
		s.FPosition();
		char direction = 'd';
		Score = 0;
		exist = false;
		game = true;
		bool pause = false;
			while (game) {

				int Speed = 150 - (Score * 10);
				std::deque<position> d = s.GetBody();
				if (_kbhit()) {
					char newdirection = _getch();

					if (newdirection == 'p') {
						pause = !pause;
					}

					if (newdirection == 'w' ||
						newdirection == 'a' ||
						newdirection == 's' ||
						newdirection == 'd') {
						bool oposite = (
							(direction == 'w' && newdirection == 's') ||
							(direction == 'a' && newdirection == 'd') ||
							(direction == 'd' && newdirection == 'a') ||
							(direction == 's' && newdirection == 'w'));
						if (d.size() == 1) {
							direction = newdirection;
						}
						if (d.size() > 1 && !oposite)
							direction = newdirection;
					}
				}
				if (!pause) {
					s.Move(direction);
				}
				COORD pos = { 0, 0 };
				SetConsoleCursorPosition(hConsole, pos);
				DrawMap(s);
				if (Score >= 10) {
					game = false;
				}
				Sleep(Speed);
			}
		system("cls");
		DrawEnd();
		char cont = _getch();
		if (cont == '1') {
			game = true;
			continue;
		}
		else if (cont == 't') {
			ScoreMenu();
		}
		if (cont != '1') {
			break;
		}
		

	}
}

/*


PRIMA DATA VERIFICA MAP-ul , DACA NU EXISTA FRUIT , FRUIT ESTE GENETAt
*/