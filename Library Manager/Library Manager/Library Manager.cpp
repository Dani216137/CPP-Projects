#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>
#include <algorithm>
#include "functions.h"




int main()
{
    book b;
    std::vector<book> v;
    ReadDocument(b, v);
    

    char a;

    while (true) {
       
        ShowMenu();
        std::cin >> a;

        switch (a) {
        case('1'): {
            system("cls");
            ShowBooks(v);
            Goback();
            break;
        }
        case('2'): {
            system("cls");
            NewBook(v);
            Goback();
            break;
        }
        case('3'):{
            system("cls");
            FindBook(v);
            Goback();
            break;
        }
        case('4'): {
            system("cls");
            RentBook(v);
            Goback();
            break;
        }
        case('5'): {
            system("cls");
            ReturnBook(v);
            Goback();
            break;
        }
        case('6'): {
            system("cls");
            DeleteBook(v);
            Goback();
            break;
        }
        case('7'): {
            system("cls");
            ModifyBook(v);
            Goback();
            break;
        }
        case('8'): {
            system("cls");
            availableBooks(v);
            Goback();
            break;
        }
        case('9'):{
            system("cls");
            UnavailableBooks(v);
            Goback();
            break;
        }
        case('S'):
        case('s'): {
            system("cls");
            SaveOption(v);
            Goback();
            break;
        }
        case('0'): {
            system("cls");
            std::cout << "See you next time !\n";
            Goback();
            return 0;
        }
        default:
            std::cout << "Invalid Option!\n";
            Goback();
                 
        }
    }
}

