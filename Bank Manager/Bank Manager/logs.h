#pragma once
#include <iostream>
#include "account.h"

std::string recordLogs(account& a);
std::string recordSearchLogs(account& a);
std::string recordDeposit(account& a,int& deposit);
std::string recordWithdraw(account& a,int&x);
std::string recordTransfer(int x,int y,int amount);
std::string recordStatus(int& x);
std::string recordDelete(int& x);
std::string recordSaveNewFile(std::string& filename);
std::string recordRewrite();