#include <iostream>
#include <vector>

using namespace std;

class Animal {
public:
    virtual void pack() {
        cout << "bam boom run " << endl;
    }
};

class Human : public Animal { // Inheritance (Is A)
public:
    void pack() {
        cout << "Mouble mouble" << endl;
    }
};

class FootballField { // Composition (has A)
public:
    vector<Animal *> animals;
};

static int example() {
    FootballField field;

    field.animals.push_back(new Human());
    field.animals.push_back(new Animal());
    field.animals.push_back(new Human());
    field.animals.push_back(new Human());
    field.animals.push_back(new Human());

    for (int i = 0; i < field.animals.size(); i++) {
        field.animals[i]->pack();
    }
}
