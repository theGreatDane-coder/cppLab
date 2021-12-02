#pragma once

#include <string>

using namespace std;

template <typename T>
class MatrixTraits {
public:
    virtual T get(int row, int col) const = 0;

    virtual void put(int row, int col, T value) = 0;

    virtual void clear() = 0;

    virtual void print() const = 0;

    virtual int size() const = 0; // how many pixels

    virtual bool equals(MatrixTraits<T>& traits) {
        return false;
    }

    virtual void copyFrom(MatrixTraits<T>& other) {
        return;
    }
};
