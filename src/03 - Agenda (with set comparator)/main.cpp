
#include <cstdlib>
#include <iostream>
#include <string>

#include "Agenda.h"

using namespace std;

int main(int argc, char **argv) {
    int choice;

    Agenda *ptr = NULL;

    while (true) {
        cout << "   ------------------" << endl;
        cout << "          Menu " << endl;
        cout << "   ------------------" << endl;

        if (ptr == NULL) {
            cout << "       1. Create a phone book " << endl;
        }

        if (ptr != NULL) {
            cout << "       2. Destroy the phone book " << endl;
            cout << "       3. Add a contact by Record " << endl;
            cout << "       4. Add a contact by details " << endl;
            cout << "       5. Remove a contact " << endl;
            cout << "       6. Search by First name " << endl;
            cout << "       7. Search by Last  name " << endl;
            cout << "       8. Search by Phone " << endl;
            cout << "       9. Show all phone book" << endl;
            cout << "       10. Print by First name sorted " << endl;
            cout << "       11. Print by Last name sorted " << endl;
            cout << "       12. Print by Phone sorted  " << endl;
        }
        cout << "       13. exit program" << endl;
        cout << endl;

        cout << " - Enter your choice (ptr = " << ptr << ") :";
        cin >> choice;

        if (ptr == NULL) {
            if (choice == 1) {
                ptr = new Agenda();
            }
        }

        if (ptr != NULL) {
            if (choice == 2) {
                delete ptr;
                ptr = NULL;
            }

            if (choice == 3 || choice == 4 || choice == 5) {
                string x1;
                string x2;
                long int x3;
                cout << "Please give the first name: ";
                cin >> x1;
                cout << "Please give the last name: ";
                cin >> x2;
                cout << "Please give the phone number: ";
                cin >> x3;

                Record rec(x1, x2, x3);

                if (choice == 3) {
                    ptr->put(rec);

                    // (*ptr) += rec;
                    // (*ptr).operator += rec;

                    // (*ptr).operator += rec
                }
                if (choice == 4) {
                    ptr->put(x1, x2, x3);
                }
                if (choice == 5) {
                    ptr->remove(x1, x2, x3);
                }
            }

            if (choice == 6 || choice == 7 || choice == 8) {
                string x;
                cout << "Please give the search argument: ";
                cin >> x;

                if (choice == 6)
                    ptr->printByFirstname(x);
                if (choice == 7)
                    ptr->printByLastname(x);
                if (choice == 8)
                    ptr->printByPhone(stol(x));
            }

            if (choice == 9) {
                ptr->print();
            }

            if (choice == 10) {
                ptr->printOrderedByFirstname();
            }

            if (choice == 11) {
                ptr->printOrderedByLastname();
            }

            if (choice == 12) {
                ptr->printOrderedByPhone();
            }

            if (choice == 13) {
                break;
            }
        }
    }

    if (ptr != NULL) {
        delete ptr;
    }

    return 0;
}