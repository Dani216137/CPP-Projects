#pragma once
#include <vector>
#include "account.h"

void accountUi(const account& x);
void mainMenu();
void waitResponse();
void displayAcc(std::vector<account>& v);
void defaultMessage();
void searchId(std::vector<account>& v, std::vector<std::string>& logs);
