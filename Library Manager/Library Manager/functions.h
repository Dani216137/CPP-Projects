#pragma once
#include<string>
#include<vector>

struct book {
    int id = 0;
    std::string title;
    std::string name;
    int year = 0;
    bool available = false;
};

extern const int MINID;
extern const int MAXID;
extern const int MINYEAR;
extern const int MAXYEAR;

void Goback();
std::string to_lower(std::string s);
bool checkfordigit(const std::string& s);
int checkint(std::string s,bool& digit);
void ShowMenu();
void ShowBooks(const std::vector<book>& v);
void NewBook(std::vector<book>& v);
void FindBook(const std::vector<book>& v);
void RentBook(std::vector<book>& v);
void ReturnBook(std::vector<book>& v);
void DeleteBook(std::vector<book>& v);
void ModifyBook(std::vector<book>& v);
void availableBooks(const std::vector<book>& v);
void UnavailableBooks(const std::vector<book>& v);
void SaveOption(const std::vector<book>& v);
void ReadDocument(book& b,std::vector<book>& v);