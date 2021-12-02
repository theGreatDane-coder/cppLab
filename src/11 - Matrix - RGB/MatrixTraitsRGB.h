#pragma once

#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Pixel {
public:
    T r, g, b;

    Pixel() : r(0), g(0), b(0) {
    }

    Pixel(T r, T g, T b) : r(r), g(g), b(b) {
    }

    ~Pixel() {
    }

    void clear() {
        r = g = b = 0;
    }

    bool operator==(const Pixel<T>& other) const {
        if (this->r == other.r && this->g == other.g && this->b == other.b) {
            return true;
        } else {
            return false;
        }
    }

    bool operator!=(const Pixel<T>& other) const {
        if (this->r == other.r && this->g == other.g && this->b == other.b) {
            return false;
        } else {
            return true;
        }
    }

    Pixel<T>& operator=(const Pixel<T>& other) {
        this->r = other.r;
        this->g = other.g;
        this->b = other.b;
        return *this;
    }

    template <typename U>
    friend ostream& operator<<(ostream& out, const Pixel<U>& other);
};

template <typename T>
ostream& operator<<(ostream& out, const Pixel<T>& other) {
    out << "<" << other.r << "," << other.g << "," << other.b << ">";
    return out;
}

template <typename T>
class MatrixTraitsRGB {
public:
    virtual Pixel<T> get(int row, int col) = 0; // pixel coordinates

    virtual void put(int row, int col, Pixel<T> value) = 0; // pixel coordinates

    virtual void clear() = 0;

    virtual void print() = 0;

    virtual int size() = 0;

    virtual bool equals(MatrixTraitsRGB<T>& traits) {
        return false;
    };

    virtual void copyFrom(MatrixTraitsRGB<T>& other) = 0;

    //    virtual void loadFrom(string filename) = 0;

    //    virtual void saveTo(string filename) = 0;

    //    virtual void copyFromBuffer(const char * ptr) = 0;
};
