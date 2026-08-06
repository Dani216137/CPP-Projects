#include <iostream>
#include "Inventory.h"
#include <stdexcept>
#include "items.h"
using namespace std;

Inventory::Inventory(int maxslot) :store(maxslot, { 0,0 }) {}

void Inventory::show(const vector<itm>& items)
{
	for (int i = 0; i < store.size(); i++) {

		if (store[i].id == 0) {
			cout << "[Empty] ";
			continue;
		}

		// cauta itemul după id
		const itm* found = nullptr;

		for (const auto& item : items) {
			if (item.id == store[i].id) {
				found = &item;
				break;
			}
		}

		if (found != nullptr) {
			cout << found->name << "x" << store[i].count <<" ";
		}
		else {
			cout << "Unknown item x" << store[i].count << " ";
		}
	}
}

bool Inventory::Additm(int item,int index)
{
	if (item < 0 || item >= store.size() || index < 0 || index >= store.size()) {
		throw out_of_range("Index or inventory out of range");
	}
	if (store[index].id == 0) {
		store[index].id = item;
		store[index].count = 1;
		return true;
	}
	if (store[index].id == item) {
		store[index].count += 1;
		return true;
	}
		if (store[index].id != item) {
		throw invalid_argument("This slot its already occupied!");
		return false;
	}
	return false;
};

bool Inventory::Swapitm(int from, int to) 
{
	if (from < 0 || from >= store.size() || (to < 0 || to >= store.size())) {
		throw out_of_range("Out of Range!");
		return false;
	}
	if (store[from].id == 0) {
		throw invalid_argument("There are no item to swap");
		return false;
	}
	if (store[from].id == store[to].id) {
		throw invalid_argument(" You can't swap a same item");  
		return false;
	}
	if (store[from].id != store[to].id) {
		swap(store[from].id, store[to].id);
		swap(store[from].count, store[to].count);
		return true;
	}
}

bool Inventory::Stackitm(int from, int to) 
{
	if (from < 0 || from >= store.size() || (to < 0 || to >= store.size())) {
		throw out_of_range("Out of Range!");
		return false;
	}
	if (store[from].id == 0) {
		throw invalid_argument("You dont have what to stack");
		return false;
	}
	if (store[to].id == 0 || store[to].id != store[from].id) {
		throw invalid_argument("You cant stack");
		return false;
	}
	if (store[from].id == store[to].id) {
		store[to].count += store[from].count;
		store[from] = { 0,0 };
		return true;
	}
	return false;
}

 bool Inventory::Splititm(int from, int to, int qua) {
	if (from < 0 || from >= store.size() || to < 0 || to >= store.size()) {
		throw out_of_range("Split out of range!");
		return false;
	}
	if (store[from].id == 0) {
		throw invalid_argument("You dont have what to Split!");
		return false;
	}
	if (store[from].id == store[to].id) {
		if (qua > store[from].count) {
			qua = store[from].count;
		}
		store[to].count += qua;
		store[from].count -= qua;
		if (store[from].count == 0) {
			store[from] = { 0,0 };
		}
		return true;
	}
	if (store[to].id == 0) {
		if (qua > store[from].count) {
			qua = store[from].count;
		}
		store[to].id = store[from].id;
		store[to].count += qua;
		store[from].count -= qua;
		if (store[from].count == 0) {
			store[from] = { 0,0 };
		}
		return true;
	}
	if (store[from].id != store[to].id) {
		throw invalid_argument("Occupied");
	}
	return false;
}
void Inventory::clear(){
	for (int i = 0;i < store.size();i++) {
		store[i].id = 0;
		store[i].count = 0;
	}
 }

int Inventory::existitm() {
	int allcount = 0;
	for (int i = 0;i < store.size();i++) {
		int tcount = 0;
		tcount = store[i].count;
		allcount += tcount;
	}
return allcount;
}
bool Inventory::isempty(){
	 for (int i = 0;i < store.size();i++) {
		 if (store[i].id != 0) {
			 throw invalid_argument("Its not empty!");
			 return false;
		 }
		 }
	 cout << "Its empty";
	return true;
}

bool Inventory::isfull() {
	for (int i = 0;i < store.size();i++) {
		if (store[i].id ==  0 ) {
			throw invalid_argument("Its not full!");
			return false;
		}
	}
	cout << "Its full!";
	return true;
}

void Inventory::eraseitm(int index){
	store.erase(store.begin()+index);
}
