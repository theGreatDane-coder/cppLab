#pragma once

template <typename T>
class BoxTraits {
public:
    virtual void put(T x) = 0;
    virtual T get() = 0;
    virtual void print() = 0;
};