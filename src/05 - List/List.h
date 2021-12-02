#pragma once

#include <set>

#include "ListTraits.h"

using namespace std;

template <typename T>
class List : public ListTraits<T>, public ListTraitsExtended<T> {
private:
    multiset<T> data;
    typename multiset<T>::iterator current;

public:
    List() {
    }

    virtual ~List() {
    }

    virtual unsigned int size() {
        return data.size();
    }

    virtual ListTraits<T>& insert(const T& item) {
        data.insert(item);
        return *this;
    }

    virtual void print() {
        for (typename multiset<T>::iterator p = data.begin(); p != data.end(); ++p) {
            cout << *p << " ";
        }
        cout << endl;
    }

    virtual const T* getCurrentElement() const {
        if (current != data.end()) {
            return &(*current);
        } else {
            return nullptr;
        }
    }

    virtual void advance() {
        if (current != data.end()) {
            ++current;
        }
    }

    virtual void rewind() {
        current = data.begin();
    }

    typename multiset<T>::iterator begin() {
        return data.begin();
    }

    typename multiset<T>::iterator end() {
        return data.end();
    }
};
