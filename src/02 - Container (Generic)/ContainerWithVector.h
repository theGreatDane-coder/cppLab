#pragma once

#include <iostream>
#include <iterator>
#include <set>
#include <vector>

#include "ContainerTraits.h"

using namespace std;

template <typename T>
class Container : public ContainerTraits<T> {
private:
    vector<T> data;

public:
    Container() {
    }

    virtual ~Container() {
    }

    virtual void add(T value) {
        data.push_back(value);
    }

    virtual unsigned int count() const {
        return data.size();
    }

    virtual bool contains(T key) const {
        // (a2): manual traversal with index (vector only)
        for (unsigned int i = 0; i < data.size(); i++) {
            if (data[i] == key) {
                return true;
            }
        }
        return false;

        // (b): iterators (recommended)
        for (vector<int>::const_iterator p = data.begin(); p != data.end(); ++p) {
            if (*p == key) {
                return true;
            }
        }
        return false;

        // (c): auto
        for (auto p = data.begin(); p != data.end(); ++p) {
            if (*p == key) {
                return true;
            }
        }
        return false;

        // (d): auto
        for (auto i : data) {
            if (i == key) {
                return true;
            }
        }
        return false;
    }

    virtual int get(unsigned int position) const {
        if (position < data.size()) {
            return data[position];
        } else {
            return 0;
        }
    }

    virtual void print() const {
        for (vector<int>::const_iterator p = data.begin(); p != data.end(); ++p) {
            cout << *p << endl;
        }
    }

    virtual void printSorted() const {
        multiset<int> sorted;

        for (vector<int>::const_iterator p = data.begin(); p != data.end(); ++p) {
            sorted.insert(*p);
        }

        for (multiset<int>::const_iterator p = sorted.begin(); p != sorted.end(); ++p) {
            cout << *p << endl;
        }
    }
};
