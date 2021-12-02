#pragma once

#include <list>

#define min(x, y) (((x) < (y)) ? x : y)

#include "List.h"

class Sandwich {
public:
    int quality;

    Sandwich(int quality = 5) : quality(quality) {
    }
};

class Cheese {
public:
    int quality;

    Cheese(int quality = 5) : quality(quality) {
    }
};

class Bread {
private:
    int quality;

public:
    Bread(int quality = 5) : quality(quality) {
    }

    Bread operator+(const Bread &right) const {
        Bread s;
        s.quality = min(this->quality, right.quality);
        return s;
    }

    Sandwich operator+(const Cheese &right) const {
        Sandwich s;
        s.quality = (this->quality + right.quality) / 2;
        return s;
    }

    Sandwich add(const Cheese &right) const {
        Sandwich s;
        s.quality = (this->quality + right.quality) / 2;
        return s;
    }

    friend Bread operator+(const Bread& left, const Bread& right) const;
};

class Table {
private:
    list<Cheese &> items;

public:
    void operator<<(const Cheese &c) {
        items.push_back(c);
    }
};

Bread operator+(const Bread& left, const Bread& right) const {
   Bread s;
   s.quality = min(left.quality, right.quality);
   return s;
}

static int example() {
    Bread b1(5);
    Bread b2(9);
    Bread b3 = b1 + b2;

    Cheese c(10);

    Sandwich s1 = b1 + c;
    Sandwich s2 = b1.add(c);

    Table table;

    table << c;
    table << b1;
    table << b2;

    cout << b1;

    //    Sandwich s = b.add(c);
}
