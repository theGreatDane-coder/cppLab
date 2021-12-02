#pragma once

#include <iostream>
#include <iterator>
#include <map>

#include "SparseMatrixTraits.h"

using namespace std;

template <typename T>
class SparseMatrix : public SparseMatrixTraits<T> {
private:
    map<Coordinates, T> data;

public:
    SparseMatrix() {
    }

    virtual ~SparseMatrix() {
    }

    virtual const T& operator()(Coordinates pos) const {
        typename map<Coordinates, T>::const_iterator p = data.find(pos);

        if (p == data.end()) {
            return getNullElement<T>();
        } else {
            return p->second;
        }
    }

    virtual T& operator()(Coordinates pos) {
        typename map<Coordinates, T>::iterator p = data.find(pos);

        if (p == data.end()) {
            data[pos] = T();
            return data[pos];
        } else {
            return data[pos];
        }
    }

    virtual void clear() {
        data.clear();
    }

    virtual void print() {
        for (typename map<Coordinates, T>::iterator p = data.begin(); p != data.end(); ++p) {
            Coordinates key = p->first;
            T value = p->second;

            cout << key.row << " " << key.col << " " << value << endl;
            // cout << p->first.row << " " << p->first.col << " " << p->second << endl;
        }
    }

    virtual bool operator == (const SparseMatrix& right) {
        if (data.size() != right.data.size()) {
            return false;
        }
        auto iter2 = right.data.begin();
        for (auto iter1 = data.begin(); iter1 != data.end(); ++iter1) {
            if (iter1->second != iter2->second) {
                return false;
            }
            ++iter2;
        }
        return true;
    }
};