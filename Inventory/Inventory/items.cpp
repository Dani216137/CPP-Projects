#include "items.h"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <sstream>


using namespace std;

void Item::loadfitems(const string& item_listtt) {

	ifstream file(item_listtt);
if(!file.is_open()){
	throw invalid_argument("There are no file!");
}
string line;
string stackStr;
getline(file, line);
while (getline(file, line)) {
	itm temp{};
	if (line.empty()) {
		continue;
	}
	if(line[0]=='/'){
		continue;
	}
	stringstream ss (line);
	if(!(ss>>temp.id>>temp.name>>temp.damage>>temp.health>>temp.buycost>>stackStr>>temp.rarity)){
		continue;
	}
	temp.stackable = (stackStr == "true");
	temp.sellcost = temp.buycost / 2;
	itmid.push_back(temp);
	}
}

void Item::Itemlist() {
	for(const auto& Item:itmid){
		cout << "Name:" << Item.name<<"\n";
		cout << "Damage:" << Item.damage << "\n";
		cout << "Health:" << Item.health << "\n";
		cout << "Price:" << Item.buycost << "\n";
		cout << "Sell Price:" << Item.sellcost << "\n";
		cout << "Stackable:" << Item.stackable << "\n";
		cout << "Rarity:" << Item.rarity << "\n";
		cout << "----------------------------------\n";
	
	}
}

const vector<itm>& Item::getItems() const {
	return itmid;
}