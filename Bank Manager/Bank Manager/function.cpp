#include "function.h"
#include "checks.h"
#include <iostream>
#include "consoleUI.h"
#include <vector>
#include "Storage.h"
#include<string>
#include "logs.h"
#include <exception>

std::string toLower(std::string& s) {
	for (auto& x : s) {
		x = tolower(static_cast<unsigned char>(x));
	}
	return s;
}

void blockUnblock(std::vector<account>& v,std::vector<std::string>& logs) {
	try {
		int x;
		if (!(checkId(v, x))) {
			return;
		}
		std::string answer;

		if (checkStatus(v, x)) {
			std::cout << "You want to change it?(yes/no)\n";
			getline(std::cin >> std::ws, answer);
			if (toLower(answer) == "yes") {
				for (auto& c : v) {
					if (c.id == x) {
						if (c.status == 1) {
							c.status = 0;
						}
						else
							c.status = 1;
					}
				}
				logs.push_back(recordStatus(x));
				std::cout << "Success!\n";
			}
			else if (toLower(answer) == "no") {
				std::cout << "No problem! Have a nice day!\n";
				return;
			}
			else {
				system("cls");
				std::cout << "Wrong format! Try again.\n";
				blockUnblock(v, logs);
			}
		}
		else {
			std::cout << "Sorry, we don't have an account with this ID :(\n";
			return;
		}
	}
	catch (std::out_of_range&) {
		std::cout << "The number is way to large!\n";
	}
}

void deleteAcc(std::vector<account>& v,std::vector<std::string>& logs) {
	int c;
	if (!checkId(v, c)) {
		return;
	}
	std::string answer;
	bool exist=false;
	for (const auto& x : v) {
		if (x.id == c) {
			exist = true;
		}
	}

	if (!exist) {
		std::cout << "We didn't find this ID :(\n";
		return;
	}
			std::cout << "Are you sure you want to delete it? Enter yes/y to confirm. Anything else will cancel: ";
			getline(std::cin >> std::ws, answer);
			if (toLower(answer) == "yes"||toLower(answer)=="y") {
				for (auto it = v.begin(); it != v.end();) {
					if (it->id == c) {
						if (it->balance == 0) {
							it = v.erase(it);
						}
						else {
							std::cout << "You can't delete an account if it still has money in it!\n";
							return;
						}
					}
					else {
						++it;
					}
				}
				logs.push_back(recordDelete(c));
				std::cout << "Success!\n";
			}
		
}

void saveModify(std::vector<account>& v,std::vector<std::string>& logs) {
	char c;
	while (true) {
		std::cout << "1. Rewrite the file\n";
		std::cout << "2. Create a new file\n";
		std::cout << "3. Main Menu\n";
		std::cout << ">";
		std::cin >> c;
		switch (c) {
		case('1'):{
			system("cls");
			rewriteFile(v,logs);
			return;
		}
		case('2'): {
			system("cls");
			saveNewFile(v, logs);
			return;
		}
		case('3'): {
			return;
		}
		default: {
			std::cout << "Wrong option!\n";
			break;
		}
		}
		}


	}



void createNewAcc(std::vector<account>& v,std::vector<std::string>& logs) {
	try {
		bool duplicate = false;
		account a;
		int x = 0;
		if (!(checkId(v, duplicate, x))) {
			return;
		}
		a.id = x;


		if (!(checkOwner(a))) {
			return;
		}

		a.acctype = "Current";

		if (!checkFirstDeposit(a)) {
			return;
		}

		v.push_back(a);
		std::string log = recordLogs(a);
		logs.push_back(log);
		system("cls");
		std::cout << "Account created successfully!\n";
	}
	catch (std::out_of_range& ) {
		std::cout << "This number is way too big!\n";
	}
}