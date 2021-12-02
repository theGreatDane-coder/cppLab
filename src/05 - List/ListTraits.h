#pragma once

//------------ Declarations for List traits used in Test1 in main.cpp

template <typename T>
class ListTraits {
public:
    virtual unsigned int size() = 0;
    virtual ListTraits<T> & insert(const T & item) = 0;
    virtual void print() = 0;
};

//------------ Declarations for List traits used in Test2 in main.cpp

template <typename T>
class ListTraitsExtended {
public:
    virtual const T * getCurrentElement() const = 0;
    virtual void advance() = 0;
    virtual void rewind() = 0;
};


// class List : public ListTraits, public ListTraitsExtended { ... }