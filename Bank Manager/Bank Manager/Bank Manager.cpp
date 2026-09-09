#include "Storage.h"
#include <iostream>
#include "account.h"
#include <vector>
#include <Windows.h>
#include <string>
#include <cctype>
#include "checks.h"
#include "consoleUI.h"
#include "transactions.h"
#include "function.h"
#include <locale>
#include <iomanip>


int main()
{
	std::cout.imbue(std::locale("en-US"));
	std::cout << std::fixed << std::setprecision(2);

	std::vector<account> v;
	std::vector<std::string> logs;

	loadFile(v);


	logs.push_back("Program started.");

	while (true) {
		mainMenu();
		
			char c;
			std::cin >> c;
			switch (c) {
			case('1'): {
				system("cls");
				displayAcc(v);;
				logs.push_back("The user checked the accounts. (Option 1)");
				takeLogs(logs);
				waitResponse();
				break;
			}
			case('2'): {
				system("cls");
				createNewAcc(v,logs);
				takeLogs(logs);
				waitResponse();
				break;
			}
			case('3'): {
				system("cls");
				searchId(v,logs);
				takeLogs(logs);
				waitResponse();
					break;
					}
			case('4'): {
				system("cls");
				depositMoney(v,logs);
				takeLogs(logs);
				waitResponse();
				break;
			}
			case('5'): {
				withdrawMoney(v,logs);
				takeLogs(logs);
				waitResponse();
				break;
			}

			case('6'): {
				system("cls");
				transferMoney(v,logs);
				takeLogs(logs);
				waitResponse();
				break;
			}
			case('7'): {
				system("cls");
				blockUnblock(v,logs);
				takeLogs(logs);
				waitResponse();
				break;
			}
			case('8'):{
				system("cls");
				deleteAcc(v,logs);
				takeLogs(logs);
				waitResponse();
				break;
			}
			case('9'): {
				system("cls");
				saveModify(v,logs);
				takeLogs(logs);
				waitResponse();
				break;
			}
			case('q'):case('Q'): {
				logs.push_back("Program closed.");
				takeLogs(logs);
				return 0;
			}


			default: {
				system("cls");
				defaultMessage();
				break;
			}

			}
			
}
	
 
}

