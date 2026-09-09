#pragma once
#include <string>
#include <vector>
#include "account.h"

bool checkforint(std::string& s);
bool checknodigit(std::string& s);
bool checkId(std::vector<account>& v, bool& duplicate,int& x);
bool checkOwner(account& a);
bool checkFirstDeposit(account& a);

bool checkId(std::vector<account>& v, int& x);
bool checkStatus(std::vector<account>& v,int& c);