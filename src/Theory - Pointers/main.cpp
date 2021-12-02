#include <iostream>

using namespace std;

int main(int argc, char *argv) {
    int x = 10;
    int y = 20;
    int z = x * y; // *:multiplication
    int &r = x;
    // int & r = 10;

    int *p = new int; // *: pointer

    cout << p << endl;

    (*p) = 30; // *: dereference operator

    cout << &x + 1;

    int *px = &x; // *px === x

    int *py = &y; // *py === y

    int q = (*px) * (*py);

    int *&rpx = px;

    cout << *&x;

    cout << *&*&*&*&*&x;

    // cout << x & y ;

    delete p;

    return 0;
}