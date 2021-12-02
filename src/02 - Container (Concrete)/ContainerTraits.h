#pragma once

class ContainerTraits {
public:
    virtual void add(int value) = 0;
    virtual unsigned int count() const = 0;
    virtual bool contains(int key) const = 0;
    virtual int get(unsigned int position) const = 0;
    virtual void print() const = 0;
    virtual void printSorted() const = 0;
};
