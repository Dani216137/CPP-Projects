#pragma once
#include <vector>
#include <fstream>
using namespace std;

struct itm {
	int id;
	string name;
	int damage;
	int health;
	int buycost;
	int sellcost;
	bool stackable;
	string rarity;

};

class Item {
private:
	vector<itm> itmid;
public:
	void loadfitems(const string& filename);
	void Itemlist();
	const vector<itm>& getItems() const;
};