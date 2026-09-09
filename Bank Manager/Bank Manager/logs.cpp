#include<iostream>
#include"logs.h"

#include <string>


std::string recordLogs(account& a) {
	return "An account was created for " + a.owner +
		" with ID: " + std::to_string(a.id) +
		" and balance: " + std::to_string(a.balance);
	

}
std::string recordSearchLogs(account& a) {
	return "Someone searched for ID: : " + std::to_string(a.id) +
			" with owner : " + a.owner + "!!!";
}

std::string recordDeposit(account& a,int& deposit) {
	return "The account with ID:" + std::to_string(a.id) + 
		   " made a deposit of : " + std::to_string(deposit) + " !!!";
}

std::string recordWithdraw(account& a,int& x) {
	return "From the account ID : " + std::to_string(a.id) + 
		   " someone withdrew " + std::to_string(x) + " !!!";
}

std::string recordTransfer(int x,int y,int amount) {
	return "The account with id : " + std::to_string(x) + 
		" sent to account ID : " + std::to_string(y) + 
		" the amount of : " + std::to_string(amount);
}

std::string recordStatus(int& x) {
	return "Someone changed the status of account id : " + std::to_string(x);

}

std::string recordDelete(int& x) {
	return "Someone deleted the account with the ID : " + std::to_string(x);
}

std::string recordSaveNewFile(std::string& filename) {
	return "Someone saved the file with name : " + filename + " !!";
}

std::string recordRewrite() {
	return "Someone rewrote the file!!";
}