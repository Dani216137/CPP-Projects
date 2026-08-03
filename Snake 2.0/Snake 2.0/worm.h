#pragma once

#include <iostream>
#include <deque>

//const char HSNAKE = '1';


struct position {
	int x;
	int y;
};

class Snake {
private:
	std::deque<position> body;

public:

	const std::deque<position>& GetBody() const;
	Snake(){}
	//position 
	//void SnakePosition(int& x, int& y);
	void Move(char move);
	void FPosition();
	bool Colision(position& newhead);
	void HitHimself(position& newhead);
	void CheckFruit(position& newhead);
	void NormalMove(position& newhead);
};