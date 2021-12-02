
#include "OrderBook.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    OrderBook* ob = new OrderBook();

    Order o1 = Order("VA1230");
    Order o2 = Order("MX2389");
    Order o3 = Order("XD1238");
    Order o4 = Order("AB7693");
    Order o5 = Order("AC3784");
    Order o6 = Order("VA1011");
    Order o7 = Order("MX1231");
    Order o8 = Order("VA0001");

    ob->add(o1);
    ob->add(o2);
    ob->add(o3);
    ob->add(o4);
    ob->add(o5);
    ob->add(o6);
    ob->add(o7);
    ob->add(o8);

    string va("VA");
    string xc("VAC");
    if (va.compare(xc.substr(0, 2)) == 0) {
        cout << "Aaaaaaaaaaaaa";
    }

    ob->print();
}