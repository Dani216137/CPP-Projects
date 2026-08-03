#pragma once

#include <vector>
#include <stdexcept>
#include"items.h"
using namespace std;

struct slot {
	int id;
	int count;
};

class Inventory {
private:
	vector <slot> store;
public:
	Inventory(int maxslot);
	void show(const vector<itm>& items);
	bool Additm(int item, int index);
	bool Swapitm(int from, int to);
	bool Stackitm(int from, int to);
	bool Splititm(int from, int to, int qua);
	void clear();
	int existitm();
	bool isempty();
	bool isfull();
	void eraseitm(int index);

};

struct item {
	string name;
};