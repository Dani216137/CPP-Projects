#include <iostream>
#include "Inventory.h"
#include "items.h"


int main()
{

    try {
        Inventory p1(6);
        Item i2;
        i2.loadfitems("items_list.txt");
    
        cout << endl;
        p1.show(i2.getItems());
        p1.Additm(1, 1);
        cout << endl;
        p1.show(i2.getItems());
        cout<<endl;
        i2.Itemlist();
       // p1.clear();
       // p1.isfull();
        /*
        p1.Swapitm(4, 1);
        p1.show();       //ok
        cout << endl;
        p1.Swapitm(4, 3);      //ok
        p1.show();
        cout << endl;
        */
    }
    catch (invalid_argument& e) {
        cout << e.what();
    }
    catch (out_of_range& e) {
        cout << e.what();
    }
}
