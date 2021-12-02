#pragma once

#include <iostream>
#include <iterator>
#include <vector>
#include <map>

#include "AgendaTraits.h"

using namespace std;

class Agenda : public AgendaTraits {
private:
    vector<Record> agenda;

public:
    Agenda() {
    }

    virtual ~Agenda(){
    }

    virtual void put(Record record) {
        agenda.push_back(record);
    };

    virtual void put(string firstname, string lastname, long int phone) {
        Record r;
        r.firstname = firstname;
        r.lastname = lastname;
        r.phone = phone;
        agenda.push_back(r);
    };

    virtual void remove(string firstname, string lastname, long int phone) {
        for (int i = 0; i < agenda.size(); i++) {
            if (agenda[i].firstname == firstname && agenda[i].lastname == lastname && agenda[i].phone == phone) {
                agenda.erase(agenda.begin() + i);
            }
        }
    };

    virtual void printByFirstname(string firstname) {
        for (int i = 0; i < agenda.size(); i++) {
            if (agenda[i].firstname == firstname) {
                cout << "first name: " << agenda[i].firstname << " last name: " << agenda[i].lastname + " phone: " << agenda[i].phone << endl;
            }
        }
    };

    virtual void printByLastname(string lastname) {
        for (int i = 0; i < agenda.size(); i++) {
            if (agenda[i].lastname == lastname) {
                cout << "first name: " << agenda[i].firstname << " last name: " << agenda[i].lastname + " phone: " << agenda[i].phone << endl;
            }
        }
    };

    virtual void printByPhone(long int phone) {
        for (int i = 0; i < agenda.size(); i++) {
            if (agenda[i].phone == phone) {
                cout << "first name: " << agenda[i].firstname << " last name: " << agenda[i].lastname + " phone: " << agenda[i].phone << endl;
            }
        }
    };

    virtual void print() {
        for (int i = 0; i < agenda.size(); i++) {
            cout << "first name: " << agenda[i].firstname << " last name: " << agenda[i].lastname + " phone: " << agenda[i].phone << endl;
        }
    };

    virtual void printOrderedByFirstname() {
        multimap<string,Record> sorted;

        for (int i = 0; i < agenda.size(); i++) {
            //sorted[agenda[i].firstname] = agenda[i];
            sorted.insert(std::pair<string, Record>(agenda[i].firstname, agenda[i]));
        }

        for (multimap<string,Record>::const_iterator p = sorted.begin(); p != sorted.end(); ++p) {
            cout << "first name: " << p->second.firstname << " last name: " << p->second.lastname << " phone: " << p->second.phone << endl;
        }
    };

    virtual void printOrderedByLastname() {
        multimap<string, Record> sorted;

        for (int i = 0; i < agenda.size(); i++) {
            //sorted[agenda[i].lastaname] = agenda[i];
            sorted.insert(std::pair<string, Record>(agenda[i].lastname, agenda[i]));
        }

        for (multimap<string, Record>::const_iterator p = sorted.begin(); p != sorted.end(); ++p) {
            cout << "first name: " << p->second.firstname << " last name: " << p->second.lastname << " phone: " << p->second.phone << endl;
        }
    };

    virtual void printOrderedByPhone() {
        multimap<int, Record> sorted;

        for (int i = 0; i < agenda.size(); i++) {
            //sorted[agenda[i].firstname] = agenda[i];
            sorted.insert(std::pair<int, Record>(agenda[i].phone, agenda[i]));
        }

        for (multimap<int, Record>::const_iterator p = sorted.begin(); p != sorted.end(); ++p) {
            cout << "first name: " << p->second.firstname << " last name: " << p->second.lastname << " phone: " << p->second.phone << endl;
        }
    };
};