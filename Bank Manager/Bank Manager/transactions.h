#pragma once
#include <vector>
#include "account.h"

inline constexpr int MAXDEPOSIT = 2000000;
inline constexpr int MAXBALANCE = 2000000000;
inline constexpr int MAXWITHDRAW = 1000000;
inline constexpr int MAXTRANSFER = 20000000;

void depositMoney(std::vector<account>& v, std::vector<std::string>& logs);
void withdrawMoney(std::vector<account>& v,std::vector<std::string>& logs);
void transferMoney(std::vector<account>& v,std::vector<std::string>& logs);