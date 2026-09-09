#pragma once
#include <vector>
#include <string>
#include "account.h"

void loadFile(std::vector<account>& v);
void rewriteFile(std::vector<account>& v,std::vector<std::string>& logs);
void saveNewFile(std::vector<account>& v,std::vector<std::string>& logs);
void writeLogs(std::vector<std::string>& logs);
void takeLogs(std::vector<std::string>& logs);