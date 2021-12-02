#pragma once

#include <iostream>
#include <list>

#include "ContainerTraits.h"

using namespace std;

class ContainerForInt : public ContainerTraits {
private:
    list<int> l;

public:
    ContainerForInt() {
    }

    virtual ~ContainerForInt() {
    }

    virtual void add(int value) {
        l.push_back(value);
    }

    virtual unsigned int count() const {
        return l.size();
    }

    virtual bool contains(int key) const {
        for (list<int>::const_iterator iter = l.begin(); iter != l.end(); ++iter) {
            if (*iter == key) {
                return true;
            }
        }
        return false;
    }

    virtual int get(unsigned int position) const {
        if (position < l.size()) {
            unsigned int counter = 0;
            for (list<int>::const_iterator iter = l.begin(); iter != l.end(); ++iter) {
                if (counter == position) {
                    return *iter;
                }
                counter++;
            }
        }
        return -1;
    }
    virtual void print() const {
        for (list<int>::const_iterator iter = l.begin(); iter != l.end(); ++iter) {
            cout << *iter << endl;
        }
    }
    virtual void printSorted() const {
        list<int> *sortedList = new list<int>(l);
        sortedList->sort();

        for (list<int>::const_iterator iter = sortedList->begin(); iter != sortedList->end(); iter++) {
            cout << *iter << endl;
        }
    }
};