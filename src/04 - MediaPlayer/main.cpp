#include <cstdlib>
#include <iostream>
#include <string>

#include "MediaPlayer.h"

using namespace std;

int main(int argc, char **argv) {
    int choice;

    MediaPlayer *ptr = NULL;

    while (true) {
        cout << "   ------------------" << endl;
        cout << "          Menu " << endl;
        cout << "   ------------------" << endl;

        if (ptr == NULL) {
            cout << "       1. Create a Media Player " << endl;
        }

        if (ptr != NULL) {
            cout << "       2. Destroy playlist " << endl;
            cout << "       3. Enter song in playlist " << endl;
            cout << "       4. Remove song from playlist " << endl;
            cout << "       5. Print playlist " << endl;
            cout << "       6. Search for Title " << endl;
            cout << "       7. Search for Band " << endl;
            cout << "       8. Play current song  " << endl;
            cout << "       9. Play first song " << endl;
            cout << "       10. Go next " << endl;
            cout << "       11.Go back " << endl;
            cout << "       12.Play last song " << endl;
            cout << "       13.Get current song " << endl;
        }
        cout << "       14. exit program" << endl;
        cout << endl;

        cout << " - Enter your choice (ptr = " << ptr << ") :";
        cin >> choice;

        if (ptr == NULL) {
            if (choice == 1) {
                ptr = new MediaPlayer();
            }
        }

        if (ptr != NULL) {
            if (choice == 2) {
                delete ptr;
                ptr = NULL;
            }

            if (choice == 3 || choice == 4) {
                string title;
                string band;
                cout << "Please give the song title: ";
                cin >> title;
                cout << "Please give the band's name: ";
                cin >> band;

                Song s(title, band);

                if (choice == 3) {
                    ptr->enqueue(s);
                }
                if (choice == 4) {
                    ptr->remove(s);
                }
            }

            if (choice == 5) {
                ptr->print();
            }

            if (choice == 6 || choice == 7) {
                string x;
                cout << "Please give the search argument: ";
                cin >> x;

                if (choice == 5)
                    ptr->searchForTitle(x);
                if (choice == 6)
                    ptr->searchForBand(x);
            }

            if (choice == 8) {
                ptr->play();
            }

            if (choice == 9) {
                ptr->first();
            }

            if (choice == 10) {
                ptr->next();
            }

            if (choice == 11) {
                ptr->previous();
            }

            if (choice == 12) {
                ptr->last();
            }

            if (choice == 13) {
                Song c = *ptr->getCurrentElement();
                cout << c.getTitle() << endl;
                cout << c.getBand() << endl;
            }

            if (choice == 14) {
                break;
            }
        }
    }

    if (ptr != NULL) {
        delete ptr;
    }

    return 0;
};