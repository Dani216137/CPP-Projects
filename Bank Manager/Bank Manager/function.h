#pragma once
#include <string>
#include <vector>
#include "account.h"

std::string toLower(std::string& s);
void blockUnblock(std::vector<account>& v,std::vector<std::string>& logs);
void deleteAcc(std::vector<account>& v,std::vector<std::string>& logs);
void saveModify(std::vector<account>& v,std::vector<std::string>& logs);
void createNewAcc(std::vector<account>& v, std::vector<std::string>& logs);

