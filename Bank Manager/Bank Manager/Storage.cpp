#include <iostream>
#include <vector>
#include "Storage.h"
#include <fstream>
#include <iomanip>
#include "logs.h"

void loadFile(std::vector<account>& v) {
	account a;

	std::ifstream ifs{ "load/Clients.txt" };

	std::string junk;
	if (!ifs) {
		std::cout << "Can't find the file!\n";
		return;
	}

	while (true) {
		if (ifs >> a.id >> std::quoted(a.owner) >> a.acctype >> a.balance >> a.status) {
			v.push_back(a);
		}
		else {
			if (ifs.eof()) {
				if (v.size() != 0) {;
					break;
				}
				if (v.size() == 0) {
					std::cout << "No accounts in the file!";
					break;
				}
			}
			if (ifs.fail()) {
				ifs.clear();
				std::getline(ifs, junk);
			}
			if (ifs.bad()) {
				std::cout << "Error opening the file!\n";
				break ;
			}
		}
	}
}

void rewriteFile(std::vector<account>& v,std::vector<std::string>& logs) {
	std::ofstream ofs{"load/Clients.txt"};
	if (!ofs) {
		std::cout << "Error opening the file!";
		return;
	}
		for (const auto& x : v) {
			ofs << x.id<<' ' << std::quoted(x.owner) <<' '<< x.acctype <<' '<< x.balance <<' '<< x.status << '\n';
		}

	logs.push_back(recordRewrite());
	std::cout << "Success!\n";
}

void saveNewFile(std::vector<account>& v,std::vector<std::string>& logs) {

	std::string file;
	std::string path = "load/";
	std::string extension = ".txt";
	std::cout << "Enter the name of the file you want to create:";
	getline(std::cin >> std::ws, file);

	std::ofstream ofs{ path+file+extension };
	if (!ofs) {
		std::cout << "Error opening the file!";
		return;
	}
		for (const auto& x : v) {
			ofs << x.id <<' ' << std::quoted(x.owner)<<' ' << x.acctype <<' '<< x.balance <<' '<< x.status << '\n';
		}
		logs.push_back(recordSaveNewFile(file));
	std::cout << "Success!\n";
}



void writeLogs(std::vector<std::string>& logs) {
	std::ofstream ofs("load/logs/logs.txt",std::ios::app);
	for (auto const& x : logs) {
		ofs << x << '\n';
	}
}

void takeLogs(std::vector<std::string>& logs) {
	writeLogs(logs);
	logs.clear();
}