#include <cstdlib>
#include <iostream>

#include "BoxForInt.h"

using namespace std;

int main(int argc, char **argv) {
    int choice = 0;

    BoxForInt *ptr = NULL;

    while (true) {
        cout << "   ------------------" << endl;
        cout << "          Menu " << endl;
        cout << "   ------------------" << endl;

        if (ptr == NULL) {
            cout << "       1. Create a box " << endl;
        }

        if (ptr != NULL) {
            cout << "       2. Destroy the box " << endl;
            cout << "       3. Put a value in the box " << endl;
            cout << "       4. Get and Print the value of the box " << endl;
            cout << "       5. Print the value of the box " << endl;
        }
        cout << "       9. exit program" << endl;
        cout << endl;

        cout << " - Enter your choice (ptr = " << ptr << ") :";
        cin >> choice;

        if (ptr == NULL) {
            if (choice == 1) {
                ptr = new BoxForInt();
            }
        }

        if (ptr != NULL) {
            if (choice == 2) {
                delete ptr;
                ptr = NULL;
            }

            if (choice == 3) {
                int x;
                cout << "Please give the value: ";
                cin >> x;

                ptr->put(x);
            }

            if (choice == 4) {
                int x = ptr->get();

                cout << "Box contains: " << x << endl;
            }

            if (choice == 5) {
                ptr->print();
            }
        }

        if (choice == 9) {
            break;
        }
    }

    if (ptr != NULL) {
        delete ptr;
    }

    return 0;
}
