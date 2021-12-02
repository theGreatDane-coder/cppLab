#pragma once

#include <string>

#include "Record.h"

using namespace std;

class AgendaTraits {
public:
    virtual void put(Record record) = 0;

    virtual void put(string firstname, string lastname, long int phone) = 0;

    virtual void remove(string firstname, string lastname, long int phone) = 0;

    virtual void printByFirstname(string firstname) = 0;

    virtual void printByLastname(string lastname) = 0;

    virtual void printByPhone(long int phone) = 0;

    virtual void print() = 0;

    virtual void printOrderedByFirstname() = 0;

    virtual void printOrderedByLastname() = 0;

    virtual void printOrderedByPhone() = 0;
};
