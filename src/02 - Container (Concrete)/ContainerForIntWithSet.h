#pragma once

#include <iostream>
#include <set>

#include "ContainerTraits.h"

using namespace std;

class ContainerForInt : public ContainerTraits {
private:
    set<int> s;

public:
    ContainerForInt() {
    }

    virtual ~ContainerForInt() {
    }

    virtual void add(int value) {
        s.insert(value);
    }

    virtual unsigned int count() const {
        return s.size();
    }

    virtual bool contains(int key) const {
        set<int>::const_iterator iter = s.find(key);

        if (iter != s.end()) {
            return true;
        }
        return false;
    }

    virtual int get(unsigned int position) const {
        if (position < s.size()) {
            set<int>::const_iterator iter = s.begin();

            for (unsigned int i = 0; i < position; i++) {
                ++iter;
            }

            return *iter;
        }
        return -1;
    }

    virtual void print() const {
        for (set<int>::const_iterator iter = s.begin(); iter != s.end(); ++iter) {
            cout << *iter << endl;
        }
    }

    virtual void printSorted() const {
        print();
    }
};