#pragma once

#include <iostream>
#include <map>

#include "ContainerTraits.h"

using namespace std;

class ContainerForInt : public ContainerTraits {
private:
    map<int, int> m;

public:
    ContainerForInt() {
    }

    virtual ~ContainerForInt() {
    }

    virtual void add(int value) {
        m[value] = 1;
    }

    virtual unsigned int count() const {
        return m.size();
    }

    virtual bool contains(int key) const {
        map<int, int>::const_iterator iter = m.find(key);

        if (iter != m.end()) {
            return true;
        }

        return false;
    }

    virtual int get(unsigned int position) const {
        if (position < m.size()) {
            map<int, int>::const_iterator iter = m.begin();

            for (unsigned int i = 0; i < position; i++) {
                ++iter;
            }
            return iter->second;
        }
        return -1;
    }

    virtual void print() const {
        for (map<int, int>::const_iterator iter = m.begin(); iter != m.end(); ++iter) {
            cout << iter->first << endl;
        }
    }
    virtual void printSorted() const {
        print();
    }
};