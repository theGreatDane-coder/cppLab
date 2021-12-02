#pragma once

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class BallotBoxTraits {
public:
    virtual void place(T item) = 0;
    virtual void place(const vector<T> &input) = 0;
    virtual void operator+=(T item) = 0;
    virtual void clear() = 0;
    virtual int getFrequency(T item) = 0; // for loop is not allowed!!!
};

// **********************************************
// DO NOT STORE ALL ELEMENTS IN A COLLECTION!!!
// **********************************************

// static int example_1() {
//     BallotBot<int> box;

//     box.place(10);
//     box += 20;
//     box.place(10);
//     box.place(10);
//     box.place(30);
//     box.place(20);

//     cout << box.getFrequency(10);   // 3
//     cout << box.getFrequency(20);   // 2
//     cout << box.getFrequency(30);   // 1
// }

// static int example_2() {
//     vector<int> input;

//     input.push_back(10);
//     input.push_back(20);
//     input.push_back(10);
//     input.push_back(10);
//     input.push_back(30);

//     BallotBot<int> box;

//     box.place(input);
//     box.place(20);
//     box += 40;

//     cout << box.getFrequency(10);   // 3
//     cout << box.getFrequency(20);   // 2
//     cout << box.getFrequency(30);   // 1
// }

// template <typename T>
// inline void BallotBotTraits<T>::place(T item) {
// }

// template <typename T>
// inline void BallotBotTraits<T>::operator+=(T item) {
// }
