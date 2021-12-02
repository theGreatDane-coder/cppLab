#pragma once

#include <string>

#include "Order.h"

using namespace std;

class OrderBookTraits {
public:
    virtual void add(Order order) = 0;

    virtual void remove(Order order) = 0;

    virtual void print() const = 0;

    virtual void printByCompany(string company_code) const = 0; // printByCompany("MA")

    virtual void printByOrderCode(string company_code, string order_code) const = 0;
};
