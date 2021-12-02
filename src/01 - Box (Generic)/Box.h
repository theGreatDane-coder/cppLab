#pragma once

#include <iostream>

#include "BoxTraits.h"

using namespace std;

template <typename T>
class Box : public BoxTraits<T> {
private:
    T value;

public:
    Box() : value(0) {
    }

    virtual ~Box() {
    }

    void put(T x) {
        value = x;
    }

    T get() {
        return value;
    }

    void print() {
        cout << value;
    }
};