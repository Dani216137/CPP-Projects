#include <iostream>
#include "consoleUI.h"
#include <vector>
#include "Storage.h"
#include "account.h"
#include "checks.h"
#include "logs.h"


void accountUi(const account& x){
	std::cout << "------------------------\n";
	std::cout << "ID : " << x.id << '\n';
	std::cout << "Owner : " << x.owner << '\n';
	std::cout << "Account type : " << x.acctype << '\n';
	std::cout << "Balance : " << x.balance /100.00<< '\n';
	std::cout << "Status : ";
	if (x.status == true) {
		std::cout << "Active\n";
	}
	else {
		std::cout << "Inactive\n";
	}
}


void waitResponse() {
	std::cout << "Press ENTER to continue...\n";
	std::cin.ignore();
	std::cin.get();

}

void mainMenu() {
	system("cls");
	std::cout << "========== BANK MANAGER ==========\n";
	std::cout << "1. Display all accounts\n";
	std::cout << "2. Create a new account\n";
	std::cout << "3. Find an account\n";
	std::cout << "4. Deposit money\n";
	std::cout << "5. Withdraw money\n";
	std::cout << "6. Transfer\n";
	std::cout << "7. Block/unblock account\n";
	std::cout << "8. Delete account\n";
	std::cout << "9. Save\n";
	std::cout << "Q. Quit\n";

	std::cout << '\n';
	std::cout << "Enter an option: >";
}

void displayAcc(std::vector<account>& v) {

	for (const auto& x : v) {
		 accountUi(x);
		 
	}

	if (v.size() == 0) {
		std::cout << "No accounts available!\n";
	}

}

void defaultMessage() {
	system("cls");
	std::cout << "Wrong option, try again!\n";
	waitResponse();
}

void searchId(std::vector<account>& v,std::vector<std::string>& logs) {
	try {
		int c = 0;
		if (checkId(v, c)) {
			bool found = false;
			for (auto& x : v) {
				if (c == x.id) {
					std::cout << "Found it!\n";
					accountUi(x);
					found = true;
					logs.push_back(recordSearchLogs(x));
				}
			}
			if (!found) {
				std::cout << "Sorry, we don't have an account with this ID :(\n";
			}

			return;
		}
	}
	catch (std::out_of_range&) {
		std::cout<<"The number is way too large!";
	}
}