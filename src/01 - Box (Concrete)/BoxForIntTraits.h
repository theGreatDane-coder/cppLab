#pragma once

class BoxForIntTraits {
public:
    virtual void put(int x) = 0;
    virtual int get() const = 0;
    virtual void print() const = 0;
};