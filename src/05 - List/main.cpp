#include <iostream>
#include <cstdio>

#include <random>

#include "List.h"

void Test1() {
    std::cout << "---------------------------- TEST 1 -------------------------------\n";
    std::cout << "Create a simple ordered list of specific items.\n";
    List<int> list;
    list.insert(1);
    list.insert(4);
    list.insert(2);
    list.insert(6);
    list.insert(3);
    list.insert(0);
    list.insert(2);
    std::cout << "List size should be 7: " << (list.size() == 7 ? "PASS" : "FAIL") << ".\n";
    std::cout << "Test should print: 0 1 2 2 3 4 6\n";
    std::cout << "Output:            ";
    list.print();

}

void Test2(int seed) {
    std::cout << "---------------------------- TEST 2 -------------------------------\n";
    std::cout << "Testing advanced List trait member functions.\n";

    srand(seed);
    const int num_items = 5;
    std::cout << "Constructing an ordered List out of " << num_items << " random elements.\n";
    List<int> list;
    for (int i = 0; i < num_items; i++) {
        list.insert(rand());
    }

    std::cout << "Now checking if elements in the list are placed in ascending order: ";
    int prev = 0;
    bool error = false;
    list.rewind();
    const int * p_element = list.getCurrentElement();
    do {
        if (p_element) {
            if (*p_element < prev) {
                error = true;
                break;
            }
            prev = *p_element;
        }
        list.advance();
        p_element = list.getCurrentElement();
    } while (p_element != nullptr);
    std::cout << (error ? "FAIL" : "PASS") << "\n";
    std::cout << "The list contents are: \n";
    list.print();
}

void Test3(int seed) {
    std::cout << "---------------------------- TEST 3 -------------------------------\n";
    std::cout << "Testing List iteration.\n";

    srand(seed);
    const int num_items = 200;
    List<int> list;

    std::cout << "Constructing an ordered List out of " << num_items << " random elements.\n";
    for (int i = 0; i < num_items; i++) {
        list.insert(rand());
    }
    std::cout << "Now checking if elements in the list are placed in ascending order: ";
    int prev = 0;
    bool error = false;
    for (auto iter = list.begin(); iter != list.end(); ++iter) {
        if (*iter < prev) {
            error = true;
            break;
        }
        prev = *iter;
    }
    std::cout << (error ? "FAIL" : "PASS") << "\n";

}

int main(int argc, char ** argv) {
    //	if (argc < 2)
    //	{
    //		std::cerr << "Please provide your student number (no leading letter) as an argument. E.g. 3015422\n";
    //		exit(-1);
    //	}
    int seed = 1111;

    Test1();
    Test2(seed);
    Test3(seed);

    return 0;

}
