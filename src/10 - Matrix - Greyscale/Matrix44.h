#pragma once

#include <iostream>

#include "MatrixTraits.h"

using namespace std;

template <typename T>
class Matrix : public MatrixTraits<T> {
private:
    T data[4][4];
    const int width, height;

public:
    Matrix(int width, int height) : width(4), height(4) {
    }

    virtual ~Matrix() {
    }

    virtual T get(int row, int col) const {
        return data[row][col];
    }

    virtual void put(int row, int col, T value) {
        data[row][col] = value;
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
