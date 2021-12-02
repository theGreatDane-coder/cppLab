#include <iostream>
#include <vector>

using namespace std;

class ShapeTraits {
public:
    virtual double area() = 0;
    virtual double perimeter() = 0;
};

class Circle : public ShapeTraits {
private:
    double R;

public:
    double area() {
        return 3.14 * R * R;
    }

    double perimeter() {
        return 2 * 3.14 * R;
    }
};

class Square : public ShapeTraits {
private:
    double edge;

public:
    double area() {
        return edge * edge:
    }

    double perimeter() {
        return edge * 4:
    }
};

class Triangle : public ShapeTraits {
private:
public:
    double area() {
    }
};