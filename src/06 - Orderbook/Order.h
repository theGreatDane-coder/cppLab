#pragma once

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>
#include <string>

using namespace std;

class Order {
private:
    string code;   // e.g: MA-0021231
    set<int> data; // paketa entolis
public:
    Order(string code) : code(code) {
    }

    Order() {
    }

    virtual ~Order() {
    }

    string getCompanyCode() const {
        return code.substr(0, 2);
    }

    string getProtocolNumber() const {
        return code.substr(2);
    }

    void print() const {
        cout << "Order : " << code << endl;
        cout << "Data  :  " << endl;

        for (set<int>::iterator p = data.begin(); p != data.end(); ++p) {
            cout << *p << ",";
        }
        cout << endl;
    }

    bool operator==(const Order& other) const {
        return this->code == other.code;
    }

    bool operator<(const Order& other) const {

        string c1 = this->getCompanyCode();
        string n1 = this->getProtocolNumber();

        string c2 = other.getCompanyCode();
        string n2 = other.getProtocolNumber();

        int i1 = atoi(n1.c_str());
        int i2 = atoi(n2.c_str());
        
        if (c1 == "VA" && c2 != "VA") {
            return true;
        }

        if (c1 != "VA" && c2 == "VA") {
            return false;
        }

        if (i1 < i2) {
            return true;
        } else {
            return false;
        }
    }
};
