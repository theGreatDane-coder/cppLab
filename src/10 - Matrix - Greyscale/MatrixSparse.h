#pragma once

#include <iostream>
#include <map>
#include <vector>

#include "MatrixTraits.h"

using namespace std;

class Coordinates {
public:
    int row, col;

    Coordinates(int row, int col) : row(row), col(col) {
    }

    bool operator<(const Coordinates& other) const {
        return row + 10000 * col < other.row + 10000 * other.col;
    }
};

template <typename T>
class Matrix : public MatrixTraits<T> {
private:
    map<Coordinates, T> data;
    const int width, height;

public:
    Matrix(int width, int height) : width(width), height(height) {
    }

    virtual ~Matrix() {
    }

    virtual T get(int row, int col) const {
        Coordinates key(row, col);

        typename map<Coordinates, T>::const_iterator p = data.find(key);

        if (p == data.end()) {
            return T();
        } else {
            return p->second;
        }
    }

    virtual void put(int row, int col, T value) {
        Coordinates key(row, col);
        data[key] = value;
    }

    virtual void clear() {
        for (int row = 0; row < height; row++) {
            for (int col = 0; col < width; col++) {
                put(row, col, 0);
            }
        }
    }

    virtual void print() const {
        for (int row = 0; row < height; row++) {
            for (int col = 0; col < width; col++) {
                cout << get(row, col) << "\t";
            }
            cout << endl;
        }
    }

    virtual int size() const {
        return height * width;
    }

    virtual bool equals(Matrix<T>& traits) {
        if (height != traits.height || width != traits.width) {
            return false;
        }

        for (int row = 0; row < height; row++) {
            for (int col = 0; col < width; col++) {
                T v1 = this->get(row, col);
                T v2 = traits.get(row, col);

                if (v1 != v2) {
                    return false;
                }
            }
        }
        return true;
    }

    virtual void copyFrom(Matrix<T>& other) { // a.copyFrom(b);
        for (int row = 0; row < height; row++) {
            for (int col = 0; col < width; col++) {
                T v2 = other.get(row, col);
                this->put(row, col, v2);
            }
        }
    }
};
