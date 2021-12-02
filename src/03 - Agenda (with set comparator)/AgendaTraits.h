#pragma once

#include <string>

#include "Record.h"

using namespace std;

class AgendaTraits {
public:
    virtual void put(Record record) = 0;

    virtual void put(string firstname, string lastname, long int phone) = 0;

    virtual void remove(string firstname, string lastname, long int phone) = 0;

    virtual void printByFirstname(string firstname) const = 0;

    virtual void printByLastname(string lastname) const = 0;

    virtual void printByPhone(long int phone) const = 0;

    virtual void print() const = 0;

    virtual void printOrderedByFirstname() const = 0;

    virtual void printOrderedByLastname() const = 0;

    virtual void printOrderedByPhone() const = 0;
};
