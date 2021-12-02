#include <cstdlib>
#include <string>
#include <vector>

#include "BallotBox.h"

using namespace std;

int main(int argc, char **argv) {
    int choice;

    BallotBox<string> box;
    
    while (true) {
        cout << "   ------------------" << endl;
        cout << "          Menu " << endl;
        cout << "   ------------------" << endl;

        cout << "       1. Clear BallotBox " << endl;
        cout << "       2. Place item " << endl;
        cout << "       3. Place items (vector) " << endl;
        cout << "       4. Place item (operator) " << endl;
        cout << "       5. Get frequency of an item " << endl;

        cout << "       6. exit program" << endl;
        cout << endl;

        cout << " - Enter your choice ";
        cin >> choice;

        if (choice == 1) {
            box.clear();
        }

        if (choice == 2) {
            string item;
            cout << "Please give item ";
            cin >> item;
            box.place(item);
        }

        if (choice == 3) {
            string item = " ";
            cout << "Please give item ";
            cin >> item;
            
            while (item != "0") {
                vector<string> i;
                i.push_back(item);
                box.place(i);
                cout << "Please give item enter 0 to stop ";
                cin >> item;
            }
        }

        if (choice == 4) {
            string item;
            cout << "Please give item ";
            cin >> item;
            box += item;
        }

        if (choice == 5) {
            string item;
            cout << "Please give item ";
            cin >> item;
            cout << "Frequency of Item " << item << " is : " << box.getFrequency(item) << endl;
        }

        if (choice == 6) {
            break;
        }
    }

    return 0;
};
