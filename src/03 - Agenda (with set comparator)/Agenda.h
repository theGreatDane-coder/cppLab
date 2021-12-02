#pragma once

#include <set>
#include <vector>

#include "AgendaTraits.h"
#include "RecordComparators.h"

using namespace std;

class Agenda : public AgendaTraits {
private:
    vector<Record> data;

public:
    Agenda() {
    }

    virtual ~Agenda() {
    }

    virtual void put(Record record) {
        data.push_back(record);
    }

    virtual void put(string firstname, string lastname, long int phone) {
        Record record(firstname, lastname, phone);
        put(record);
    }

    virtual void remove(string firstname, string lastname, long int phone) {
        for (vector<Record>::iterator it = data.begin(); it != data.end(); ++it) {
            Record &rec = *it;

            if (rec.getFirstname() == firstname && rec.getLastname() == lastname && rec.getPhone() == phone) {
                data.erase(it);
                break;
            }
        }
    }

    virtual void printByFirstname(string firstname) const {
        for (vector<Record>::const_iterator it = data.begin(); it != data.end(); ++it) {
            if (it->getFirstname() == firstname) {
                it->print();
            }
        }
    }

    virtual void printByLastname(string lastname) const {
        for (vector<Record>::const_iterator it = data.begin(); it != data.end(); ++it) {
            if (it->getLastname() == lastname) {
                it->print();
            }
        }
    }

    virtual void printByPhone(long int phone) const {
        for (vector<Record>::const_iterator it = data.begin(); it != data.end(); ++it) {
            if (it->getPhone() == phone) {
                it->print();
            }
        }
    }

    virtual void print() const {
        for (vector<Record>::const_iterator it = data.begin(); it != data.end(); ++it) {
            it->print();
        }
    }

    virtual void printOrderedByFirstname() const {
        set<Record, FirstnameComparator> sorteddata;

        for (vector<Record>::const_iterator it = data.begin(); it != data.end(); ++it) {
            sorteddata.insert(*it);
        }

        for (set<Record>::const_iterator it = sorteddata.begin(); it != sorteddata.end(); ++it) {
            it->print();
        }
    }

    virtual void printOrderedByLastname() const {
        set<Record, LastnameComparator> sorteddata;

        for (vector<Record>::const_iterator it = data.begin(); it != data.end(); ++it) {
            sorteddata.insert(*it);
        }

        for (set<Record>::const_iterator it = sorteddata.begin(); it != sorteddata.end(); ++it) {
            it->print();
        }
    }
    virtual void printOrderedByPhone() const {
        set<Record, PhoneComparator> sorteddata;

        for (vector<Record>::const_iterator it = data.begin(); it != data.end(); ++it) {
            sorteddata.insert(*it);
        }

        for (set<Record>::const_iterator it = sorteddata.begin(); it != sorteddata.end(); ++it) {
            it->print();
        }
    }
};