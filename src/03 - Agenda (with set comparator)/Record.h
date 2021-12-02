#pragma once

#include <iostream>
#include <string>

using namespace std;

class Record {
private:
    string firstname;
    string lastname;
    long int phone;

public:
    Record() {}

    Record(string firstname, string lastname, long int phone) : firstname(firstname), lastname(lastname), phone(phone) {
    }

    void print() const {
        cout << firstname << " " << lastname << " " << phone << endl;
    }

    string getFirstname() const {
        return firstname;
    }

    string getLastname() const {
        return lastname;
    }

    long int getPhone() const {
        return phone;
    }
};