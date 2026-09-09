#include <string>
#include "checks.h"
#include <iostream>
#include "consoleUI.h"
#include "function.h"
#include "transactions.h"


bool checkforint(std::string& s) {
	int count = 0;
	if (s.size() == 0) {
		return false;
	}
	for (const auto& x : s) {
		if (!(isdigit(static_cast<unsigned char>(x)))) {
			++count;
		}
	}
	if (count != 0) {
		return false;
	}
	return true;
}

bool checknodigit(std::string& s) {

	for (auto& x : s) {
		if (std::isdigit(static_cast<unsigned char>(x))) {
			return true;
		}
	}
	return false;

}

bool checkId(std::vector<account>& v,bool& duplicate,int& x ) {
	std::string id;
	std::cout << "Enter the id, must be unique!:";
	std::cin >> id;
	if (!(checkforint(id))) {
		std::cout << "The ID must contain only digits!\n";
		return false;
	}
	 x = std::stoi(id);
	if (x < 0 || x>100) {
		std::cout << "The ID must be in the range 0-100!\n";
		return false;
	}

	for (auto& f : v) {
		if (f.id == x) {
			duplicate = true;
		}
	}
	if (duplicate) {
		std::cout << "This id already exists!\n";
		return false;
	}
	return true;
}

bool checkOwner(account& a) {
	std::cout << "Owner name:";
	std::getline(std::cin >> std::ws, a.owner);
	if (checknodigit(a.owner)) {
		std::cout << "Owner name can't contain digits!\n";
		return false;
	}
	return true;
}

bool checkFirstDeposit(account& a) {
	std::string depo;
	std::cout << "First deposit:";
	std::getline(std::cin >> std::ws, depo);
	if (!(checkforint(depo))) {
		std::cout << "Wrong format! The amount must contain only digits and can't be negative or a decimal number.";
		return false;
	}
	a.balance = std::stoi(depo);
	if (a.balance > MAXDEPOSIT) {
		std::cout << "You can't deposit more than 20,000.00 at once!\n";
		return false;
	}
	a.status = true;
		return true;
}

bool checkId(std::vector<account>& v, int& x) {

	std::string id;
	std::cout << "Enter the id:";
	std::cin >> id;
	if (!(checkforint(id))) {
		std::cout << "The ID must contain only digits!\n";
		return false;
	}
	x = std::stoi(id);
	if (x < 0 || x>100) {
		std::cout << "The ID must be in the range 0-100!\n";
		return false;
	}


	return true;
}

bool checkStatus(std::vector<account>& v,int& c) {



	for (auto& x : v) {
		if (x.id == c) {
			if (x.status == 0) {
				std::cout << "Account blocked!\n";
				return true;
				}
			if(x.status==1){
				std::cout << "Account available!\n";
				return true;
			}
		}
	}
	return false;
}
