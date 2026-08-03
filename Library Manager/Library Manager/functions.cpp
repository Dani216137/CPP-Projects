#include <iostream>
#include <string>
#include "functions.h"
#include <vector>
#include <fstream>
#include <iomanip>
#include <cctype>

int const MINID = 0;
int const MAXID = 100;
int const MINYEAR = 1500;
int const MAXYEAR = 2026;

void Goback() {
    std::cout << "Press ENTER to continue...";
    std::cin.ignore();
    std::cin.get();
}


std::string to_lower(std::string s) {
    for (char& c : s) {
        c = std::tolower(static_cast<unsigned char>(c));
    }
    return s;
}

bool checkfordigit(const std::string& s) {

    for (auto x : s) {
        if (std::isdigit(static_cast<unsigned char>(x))) {
            return true;
        }
    }
    return false;
}

int checkint(std::string s,bool& digit) {
    digit = true;
    int count = 0;
    int val = 0;
    if (s.empty()) {
        std::cout << "You have to enter something!\n";
        digit = false;
        return 1;
    }
    for (const auto& x : s) {
        if (!(isdigit(x))) {
            ++count;
        }
    }

    if (count != 0) {
        digit = false;
        return 1;
    }
    if (count == 0) {
        for (auto& x : s) {
            val = val * 10 + (x - '0');
        }
        digit = true;
    }
    return val;


}


void ShowMenu() {
    system("cls");
    std::cout << "============Library Manager============\n\n";
    std::cout << "1. Display all books\n";
    std::cout << "2. Add a new book\n";
    std::cout << "3. Find a book by ID\n";
    std::cout << "4. Rent a book\n";
    std::cout << "5. Return a book\n";
    std::cout << "6. Delete a book\n";
    std::cout << "7. Modify a book\n";
    std::cout << "8. Show available books\n";
    std::cout << "9. Show Missing books\n";
    std::cout << "s. Save the changes\n";
    std::cout << "0. EXIT\n";

    std::cout << "Enter option: ";
}


void ShowBooks(const std::vector<book>& v) {
    if (v.empty()) {
        std::cout << "You dont have any book!\n";
    }
    for (const auto& x : v) {
        std::string av = " ";
        if (x.available) {
            av = "available";
        }
        else {
            av = "Unavailable";
        }
        std::cout << "------------------------\n";
        std::cout << "ID: " << x.id << "\n";
        std::cout << "Title of book: " << x.title << '\n';
        std::cout << "Author name: " << x.name<< '\n';
        std::cout << "Year: " << x.year << '\n';
        std::cout << "Status: " << av << '\n';
    }
}

void NewBook(std::vector<book>& v) {
    book a;
    bool duplicate = false;
    std::cout << "Enter the id of the book (must be unique)\n";
    bool digit = true;
    std::string check;
    std::cin >> check;
    std::cout << '\n'; 
    int n = checkint(check,digit);
    if (digit) {
        if (n >= MINID && n <= MAXID) {
            for (const auto& x : v) {
                if (x.id == n) {
                    duplicate = true;
                    std::cout << "This id its already exist!!\n";
                    break;
                }
            }
            if (!duplicate) {
                a.id = n;
                std::cout << '\n';
                std::cout << "Enter the title : \n";
                std::getline(std::cin>>std::ws, a.title);

                for (auto& x : v) {
                    if (to_lower(x.title) == to_lower(a.title)) {
                        std::cout << "This title already exist!!";
                        duplicate = true;
                        break;
                    }
                }
                if (!duplicate) {
                    std::cout << '\n';
                    std::cout << "Enter the name of Author:";
                    std::getline(std::cin >> std::ws, a.name);              
                    if(checkfordigit(a.name)){
                        std::cout << "The name can't have digits inside!!\n";
                        return;
                    }

                    std::cout << "Year :";
                    std::string checks;
                    std::cin >> checks;
                    std::cout << '\n';
                    int m = checkint(checks, digit);
                    if (!digit) {
                        std::cout << "Bad format for Year!\n";
                        return;
                    }
                    if (m >= MINYEAR && m <= MAXYEAR) {
                        std::cout << '\n';
                        a.year = m;
                        a.available = true;
                        v.push_back(a);
                        system("cls");
                        std::cout << "The book " << a.title << " was added with Successs!\n";
                    }
                    else {
                        std::cout << "Year its out of range!\n";
                    }
                }
            }
        }
        else {
            std::cout << "Out of range! must be 0-100!\n";
        }
    }
    else {
        std::cout << "Bad format!\n";
    }
}

void FindBook(const std::vector<book>& v) {
    std::cout << "Enter the ID of book you are looking for:";
    bool digit = true;
    std::string check;
    std::cin >> check;
    std::cout << '\n';
    int n = checkint(check, digit);
    if (digit) {
        bool found = false;
        std::cout << '\n';
        for (const auto& x : v) {
            if (x.id == n) {
                std::cout << "Found it!\n";
                std::cout << "Title : " << x.title << '\n';
                std::cout << "Author: " << x.name << '\n';
                std::cout << "Year: " << x.year << '\n';
                if (x.available) {
                    std::cout << "Status: available\n";
                }
                else {
                    std::cout << "Status: Unavailable\n";
                }
                found = true;

            }
        }
        if (!found) {
            std::cout << "The book doesn't exist!\n";
            return;
        }
    }
    else {
        std::cout << "Bad format!\n";
        return;
    }
}

void RentBook(std::vector<book>& v) {

    std::cout << "Enter the id of the book u want to rent:";
    bool digit = true;
    std::string check;
    std::cin >> check;
    std::cout << '\n';
    int n = checkint(check, digit);
    std::cout << '\n';
    if (digit) {
        bool exist = true;
        bool available = true;

        for (auto& x : v) {
            if (x.id == n) {
                exist = false;
                if (x.available) {
                    std::cout << "Have fun!\n";
                    x.available = false;
                    available = false;
                    break;
                }
                else {
                    available = true;
                }
            }
        }
        if (exist) {
            std::cout << "This book don't exist\n";
            return;
        }
        if (available) {
            std::cout << "Its not available right now!!\n";
        }
    }
    else {
        std::cout << "Bad format for id!\n";
    }
}

void ReturnBook(std::vector<book>& v) {

    std::cout << "Type the ID of book you want to return:";
    bool digit = true;
    std::string check;
    std::cin >> check;
    std::cout << '\n';
    int n = checkint(check, digit);
    if (digit) {
        bool exist = false;
        std::cout << '\n';
        bool duplicate = false;

        for (auto& x : v) {
            if (x.id == n) {
                exist = true;
                if (x.available) {
                    std::cout << "The book its already here!\n";
                    duplicate = true;
                    break;
                }
                else {
                    x.available = true;
                }

            }
        }
        if (!exist) {
            std::cout << "We dont have this book!\n";
            return;
        }

        if (!duplicate) {
            std::cout << "Success!\n";
        }
    }
    else {
        std::cout << "Bad Format!\n";
    }
}

void DeleteBook(std::vector<book>& v) {


    if (v.empty()) {
        std::cout << " We dont have any book right now!\n";
        return;
    }

    std::cout << "Enter the ID of the book you want to delete :\n";
    bool digit = true;
    std::string check;
    std::cin >> check;
    std::cout << '\n';
    int n = checkint(check, digit);
    if (digit) {
        bool exist = false;

        for (auto it = v.begin(); it != v.end();) {
            if (it->id == n) {
                exist = true;
                it = v.erase(it);
                break;
            }
            else
                ++it;
        }
        if (!(exist))
        {
            std::cout << "No book with this id!\n";
            return;
        }
        std::cout << "Success!\n";
    }
    else {
        std::cout << "Bad Format!\n";
    }
}

void ModifyBook(std::vector<book>& v) {
   
    std::cout << "Enter the id of the book you want to modify:";
    bool digit = true;
    std::string check;
    std::cin >> check;
    std::cout << '\n';
    bool found = false;
    int n = checkint(check, digit);
    if (digit) {
        for (auto& x : v) {
            if (n == x.id) {
                found = true;
                std::cout << " Book found!\n";
                std::cout << "1. Change title\n";
                std::cout << "2. Change author\n";
                std::cout << "3. Change year\n";
                char a;
                std::cin >> a;
                std::cout << '\n';
                switch (a) {
                case('1'): {
                    std::cout << "New Title:";
                    std::string newtitle;
                    std::getline(std::cin >> std::ws, newtitle);
                    bool duplicate = false;
                    for (auto& s : v) {
                        if (to_lower(newtitle) == to_lower(s.title)) {
                            std::cout << "This title already exist!!";
                            duplicate = true;
                            break;
                        }
                    }
                    if (!duplicate) {
                        std::cout << "Success!\n";
                        x.title = newtitle;
                    }
                    break;
                }
                case('2'): {
                    std::cout << "New author:\n";
                    std::cout << "Enter name:";
                    std::string newname;
                    std::getline(std::cin >> std::ws, newname);
                    std::cout << '\n';
                    
                    if (checkfordigit(x.name)) {
                        std::cout << "The name can't have digits inside!!\n";
                        return;
                    }
                    x.name = newname;
                    std::cout << "\nSuccess!\n";
                    break;
                }

                case('3'): {

                    std::cout << "Enter the new year:";
                    std::string check;
                    std::cin >> check;
                    std::cout << '\n';
                    int n = checkint(check, digit);
                        if (digit) {
                            if (n >= MINYEAR && n <= MAXYEAR) {
                                x.year = n;
                                std::cout << "Good format\n";
                                break;
                            }
                            else {
                                std::cout << "Out of Range!\n";
                                return;
                            }
                        }
                        if (!digit) {
                            std::cout << "Bad format!!\n";
                            break;
                        }
                        break;   
                }

                }
            }
        }
        if (!found) {
            std::cout << "We dont have this book!\n";
            return;
        }
    }
    else {
        std::cout << "Bad format!\n";
    }
}

void availableBooks(const std::vector<book>& v) {
    int availableCount = 0;
    for (const auto& x : v) {
        if (x.available) {
            std::cout << "------------------------\n";
            std::cout << "ID: " << x.id << "\n";
            std::cout << "Title of book: " << x.title << '\n';
            std::cout << "Author name: " << x.name << '\n';
            std::cout << "Year: " << x.year << '\n';
            ++availableCount;
        }
    }
        if (availableCount == 0) {
            std::cout << "No books available!\n";
    }
}

void UnavailableBooks(const std::vector<book>& v) {
    int availableCount = 0;
    for (const auto& x : v) {
        if (!(x.available)) {
            std::cout << "------------------------\n";
            std::cout << "ID: " << x.id << "\n";
            std::cout << "Title of book: " << x.title << '\n';
            std::cout << "Author name: " <<x.name<< '\n';
            std::cout << "Year: " << x.year << '\n';
            ++availableCount;

        }
    }
    if (availableCount == 0) {
        std::cout << "No books are missing!\n";
    }
}

void SaveOption(const std::vector<book>& v) {
    std::cout << "Are you sure you want to save?(YES/NO)\n";
    std::string ans;
    std::cin >> ans;
    std::string g = to_lower(ans);
    if (g == "yes") {
        std::ofstream ofs{ "library.txt" };
        if (!ofs) {
            std::cout << "Error to write in file!\n";
            return ;
        }
        for (const auto& b : v) {
            ofs << b.id << ' ' << std::quoted(b.title) << ' ' << std::quoted(b.name) << ' ' << b.year << ' ' << b.available << '\n';
        }
        std::cout << "Success!\n";
    }
}


void ReadDocument(book& b,std::vector<book>& v) {
    std::ifstream ifs{ "library.txt" };

    if (!ifs) {
        std::cout << "Cannot open the file!\n";
        return ;
    }

    std::string junk;

    while (true) {
        if (ifs >> b.id >> std::quoted(b.title) >> std::quoted(b.name) >> b.year >> b.available) {
            v.push_back(b);
        }
        else {
            if (ifs.eof()) {
                break;
            }
            if (ifs.fail()) {
                ifs.clear();
                ifs >> junk;
            }
            if (ifs.bad()) {
                std::cout << "File corupted!";
                return ;
            }
        }
    }
}

//de facut verificarea la case 7 cand bagi numele autorului , sa nu fie Digit , si cred ca la verificare la toat numele , autor si titlu