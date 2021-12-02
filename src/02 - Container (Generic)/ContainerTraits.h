#pragma once

template <typename T>
class ContainerTraits {
public:
    virtual void add(T value) = 0;
    virtual unsigned int count() const = 0;
    virtual bool contains(T key) const = 0;
    virtual int get(unsigned int position) const = 0;
    virtual void print() const = 0;
    virtual void printSorted() const = 0;
};
