
#include <cstdlib>

#include "ContainerForIntWithMap.h"

using namespace std;

int main(int argc, char **argv) {
    int choice;

    ContainerForInt *ptr = NULL;

    while (true) {
        cout << "   ------------------" << endl;
        cout << "          Menu " << endl;
        cout << "   ------------------" << endl;

        if (ptr == NULL) {
            cout << "       1. Create a container " << endl;
        }

        if (ptr != NULL) {
            cout << "       2. Destroy the container " << endl;
            cout << "       3. Add a value in the container " << endl;
            cout << "       4. Get and Print the value of the container " << endl;
            cout << "       5. Print the values of the container " << endl;
            cout << "       6. Print the values of the container ordered " << endl;
            cout << "       7. Count the values of the container " << endl;
        }
        cout << "       9. exit program" << endl;
        cout << endl;

        cout << " - Enter your choice (ptr = " << ptr << ") :";
        cin >> choice;

        if (ptr == NULL) {
            if (choice == 1) {
                ptr = new ContainerForInt();
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

                ptr->add(x);
            }

            if (choice == 4) {
                unsigned int pos;

                cout << "Position: ";
                cin >> pos;

                int x = ptr->get(pos);

                cout << "Value is: " << x << endl;
            }

            if (choice == 5) {
                ptr->print();
            }

            if (choice == 6) {
                ptr->printSorted();
            }

            if (choice == 7) {
                unsigned int c = ptr->count();

                cout << "Count is: " << c << endl;
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
