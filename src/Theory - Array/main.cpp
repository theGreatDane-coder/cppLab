#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    int *x = new int[3];
    x[0] = 10;
    x[1] = 5;
    x[2] = 15;

    cout << x[0] << endl;
    cout << x[1] << endl;

    cout << *x << endl;
    cout << *x + 1 << endl;
    cout << *(x + 1) << endl;

    vector<int> vx;

    vx.push_back(10);
    vx.push_back(5);
    vx.push_back(5);
    vx.push_back(5);
    vx.push_back(5);
    vx.push_back(5);

    cout << vx[0];
    cout << vx[1];

    delete[] x;

    return 0;
}