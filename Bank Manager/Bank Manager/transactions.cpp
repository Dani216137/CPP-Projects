#include<vector>
#include"account.h"
#include "checks.h"
#include <iostream>
#include "consoleUI.h"
#include <exception>
#include "logs.h"
#include "transactions.h"


void depositMoney(std::vector<account>& v,std::vector<std::string>& logs) {
	try {
		std::cout << "Enter the ID of the account you want to deposit into: \n";
		int x;
		if (!(checkId(v, x))) {
			return;
		}
		for (const auto& c : v) {
			if (c.id == x) {
				if (c.status == 0) {
					std::cout << "This account is blocked!\n";
					return;
				}
				if (c.balance > MAXBALANCE) {
					std::cout << "This account is already full!\n";
					std::cout << "The limit is: 20,000,000.00 \n";
					return;
				}
			}
		}
		bool exist = false;
		std::string amount;
		for (auto& c : v) {
			if (c.id == x) {
				std::cout << "Found it!\n";
				std::cout << '\n';
				exist = true;
				std::cout << "Enter the amount you want to deposit : ";
				getline(std::cin >> std::ws, amount);

				if (checkforint(amount)) {
						int g = std::stoi(amount);
						if (g == 0) {
							std::cout << "You can't make a transaction with 0 value!\n";
							return;
						}

						if (g > MAXDEPOSIT) {
							std::cout << "You can't deposit more than 20,000.00 at once!\n";
							return;
						}
						if (c.balance + g > MAXBALANCE) {
							std::cout << "Your balance can't be more than 20,000,000.00 after this deposit!\n";
							return;
						}

						c.balance += g;
						std::cout << "Success!\n";
						logs.push_back(recordDeposit(c, g));

				}
				else {
					std::cout << "Wrong format! The amount must contain only digits.\n";
				}

			}
		}
		if (!exist) {
			std::cout << "Sorry, we don't have an account with this ID :(\n";
			return;
		}
	}
	catch (std::out_of_range&) {
		std::cout << "The number is way too large!\n";
	}

}

void withdrawMoney(std::vector<account>& v,std::vector<std::string>& logs) {
	try {
		std::cout << "Enter the ID of the account you want to withdraw money from: ";
		int x;
		if (!(checkId(v, x))) {
			return;
		}
		std::string amount;
		bool exist = false;
		for ( auto& c : v) {
			if (c.id == x) {
				exist = true;
				std::cout << "Found it!\n";
				if (c.status == 0) {
					std::cout << "This account is blocked!\n";
					return;
				}
				std::cout << "Enter the amount you want to withdraw : ";
				std::getline(std::cin >> std::ws, amount);
				if (checkforint(amount)) {

						int i = std::stoi(amount);
						if ((c.balance - i) < 0) {
							std::cout << "You don't have enough balance!\n";
							return;
						}
						if (i == 0) {
							std::cout << "You can't make a transaction with a value of 0!\n";
							return;
						}
						if (i > MAXWITHDRAW) {
							std::cout << "You can't withdraw more than 10,000.00 at once!\n";
							return;
						}
						c.balance -= i;
						logs.push_back(recordWithdraw(c, i));
						std::cout << "Success!!\n";
					
				}
				else {
					std::cout << "Wrong format! The amount must contain only digits.\n";
					return;
				}

			}
		}
		if (!exist) {
			std::cout << "Sorry, we don't have an account with this ID :(\n";
			return;
		}
	}
	catch (std::out_of_range&) {
		std::cout << "The number is way too large!\n";
	}
}

void transferMoney(std::vector<account>& v,std::vector<std::string>& logs) {
	try {
		std::cout << "Sender: ";
		int x;
		if (!(checkId(v, x))) {
			return;
		}
		bool sender = false;

		std::cout << "Receiver: ";
		int y;
		if (!(checkId(v, y))) {
			return;
		}
		bool getter = false;
		if (x == y) {
			std::cout << "You entered the same account for sender and receiver!\n";
			return;
		}
		for (auto c : v) {
			if (c.id == x) {
				sender = true;
				if (!c.status) {
					std::cout << "The sender is blocked!\n";
					return;
				}
			}
			if (c.id == y) {
				if (!c.status) {
					std::cout << "The receiver is blocked!\n";
					return;
				}
				getter = true;

			}
		}
		if (!sender) {
			std::cout << "We didn't find the sender's ID!\n";
			return;
		}
		if (!getter) {
			std::cout << "We didn't find the receiver's ID!\n";
			return;
		}


		std::cout << "Enter the amount you want to transfer:";
		std::string amount;
		getline(std::cin >> std::ws, amount);
		std::cout << '\n';
		if (!(checkforint(amount))) {
			std::cout << "The amount must contain only digits and must be positive!\n";
			return;
		}
		int mtransfer = std::stoi(amount);
		if (mtransfer == 0) {
			std::cout << "You can't make a transaction with a value of 0!\n";
			return;
		}


		for (const auto& c : v) {

			if (c.id == x) {

				if (c.balance == 0) {
					std::cout << "Not enough funds!\n";
					return;
				}

				if (c.balance - mtransfer < 0) {
					std::cout << "Not enough balance!\n";
					return;
				}
				if (mtransfer > MAXTRANSFER) {
					std::cout << "You can't transfer more than 200,000.00!\n";
					return;
				}
;
			}
			if (c.id == y) {
				if (c.balance + mtransfer > MAXBALANCE) {
					std::cout << "The receiver's balance can't exceed 20,000,000.00!\n";
					return;
				}
			}
		}


		for (auto& c : v) {
			if (c.id == x) {
				c.balance -= mtransfer;
			}
			if (c.id == y) {
				c.balance += mtransfer;
			}
		}
		logs.push_back(recordTransfer(x, y, mtransfer));
		std::cout << "Success!\n";
	}
	catch (std::out_of_range&) {
		std::cout << "The number is way too large!\n";
	}
}