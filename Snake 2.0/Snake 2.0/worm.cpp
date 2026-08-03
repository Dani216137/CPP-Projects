#include <iostream>
#include <deque>
#include <algorithm>
#include <deque>
#include "worm.h"
#include "table.h"


bool eatFruit = false;


const std::deque<position>& Snake::GetBody() const {
	return body;
}

void Snake::Move(char move) {
	bool eatFruit = false;
	position head = body.front();
	position newhead = head;
	switch (move) {
	case('w'): {
		newhead.x -= 1;

		break;
	}
	case('s'): {
		newhead.x += 1;
		break;

	}
	case('a'): {
		newhead.y -= 1;
		break;

	}
	case('d'):
		newhead.y += 1;
		break;

	}
	if (Colision(newhead)) {
		HitHimself(newhead);
		CheckFruit(newhead);
		NormalMove(newhead);
	}
}


bool Snake::Colision(position& newhead){
	
	
	return newhead.x > 0 &&
		newhead.x < 19 &&
		newhead.y > 0 &&
		newhead.y < 19;

}

void Snake::HitHimself(position& newhead){

	for (position& x : body) {
		if (x.x == newhead.x && x.y == newhead.y) {
			game = false;
			break;
		}
	}
}

void Snake::CheckFruit(position& newhead) {
	if (Map[newhead.x][newhead.y] == FRUIT) {
		body.push_back(newhead);
		eatFruit = true;
		exist = false;
		++Score;
	}
}

void Snake::NormalMove(position& newhead) {
	body.push_front(newhead);
	body.pop_back();
	if (eatFruit) {
		eatFruit = false;

	}
}

void Snake::FPosition() {
	body.push_back({ 2,3 });
}

