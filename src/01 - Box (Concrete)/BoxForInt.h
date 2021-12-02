#pragma once

#include <iostream>

#include "BoxForIntTraits.h"

using namespace std;

class BoxForInt : public BoxForIntTraits {
private:
    int value;

public:
    BoxForInt() : value(0) {
    }

    virtual ~BoxForInt() {
    }

    void put(int x) {
        value = x;
    }

    int get() const {
        return value;
    }

    void print() const {
        cout << value;
    }
};