#pragma once

#include <iostream>
#include <set>

#include "OrderBookTraits.h"

class OrderBook : public OrderBookTraits {
private:
    set<Order> data;

public:
    OrderBook() {}

    virtual ~OrderBook() {}

    virtual void add(Order order) {
        data.insert(order);
    }

    virtual void remove(Order order) {
        for (set<Order>::iterator iter = data.begin(); iter != data.end(); ++iter) {
            if (*iter == order) {
                data.erase(iter);
                break;
            }
        }
    }

    virtual void print() const {
        for (set<Order>::const_iterator iter = data.begin(); iter != data.end(); ++iter) {
            iter->print();
        }
    }

    virtual void printByCompany(string company_code) const {
        for (set<Order>::const_iterator iter = data.begin(); iter != data.end(); ++iter) {
            if (iter->getCompanyCode() == company_code) {
                iter->print();
            }
        }
    }

    virtual void printByOrderCode(string company_code, string order_code) const {
        for (set<Order>::const_iterator iter = data.begin(); iter != data.end(); ++iter) {
            if (iter->getCompanyCode() == company_code && iter->getProtocolNumber() == order_code) {
                iter->print();
            }
        }
    }
};