#include <iostream>
#include <string>

#include "MatrixSparse.h"

int main(int argc, char** argv) {

    Matrix<int>* ptr = new Matrix<int>(4, 4);
    int choice;

    while (true) {
        cout << "   ------------------" << endl;
        cout << "         Matrix " << endl;
        cout << "   ------------------" << endl;

        cout << "       1. Get data " << endl;
        cout << "       2. Put data " << endl;
        cout << "       3. Clear data " << endl;
        cout << "       4. Print data " << endl;
        cout << "       5. Check equal " << endl;
        cout << "       6. Copy from table " << endl;
        cout << "       7. exit program" << endl;
        cout << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int x, y;
            cout << "Give coordinates to get value ";
            cin >> x;
            cin >> y;
            cout << ptr->get(x, y) << endl;
        }
        if (choice == 2) {
            int x, y;
            cout << "Give coordinates and value to insert";
            cin >> x;
            cin >> y;
            int value;
            cin >> value;
            ptr->put(x, y, value);
        }
        if (choice == 3) {
            ptr->clear();
        }
        if (choice == 4) {
            ptr->print();
        }
        if (choice == 5) {
            //  cout << " Give new table 4x4 values" << endl;
            // int val;
            // MatrixTraits<int>* table;
            // for (int i = 0; i < sizeof(table) / 2; i++) {
            //      for (int j = 0; j < sizeof(table) / 2; j++) {
            //          cin >> val;
            //          p->put(i, j, val);
            //      }
            //   }
            //   if ((ptr->equals(table)) == true) {
            //      cout << " Tables are equal";
            //   }
            //   else {
            //      cout << " Tables are nto equal";
            //    }
        }
        if (choice == 6) {
            //  cout << " Give new table 4x4 values to copy" << endl;
            //  int val;
            //  for (int i = 0; i < 4; i++) {
            //      for (int j = 0; j < 4 ; j++) {
            //          cin >> val;
            //          p->put(i, j, val);
            //      }
            //  }
            //  ptr->copyFrom(p);
            //  ptr->print();
        }
        if (choice == 7) {
            break;
        }
    }

    delete ptr;

    return 0;
}