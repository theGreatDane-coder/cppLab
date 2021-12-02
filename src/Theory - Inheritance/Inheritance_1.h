#include <iostream>
#include <vector>

using namespace std;

class Animal {
public:
    virtual void sing() = 0;
};

class Cat : public Animal {
public:
    void sing() {
        cout << "Niaou" << endl;
    }
};

class Dog : public Animal {
public:
    void sing() {
        cout << "Gab" << endl;
    }
};

class Cow : public Animal {
public:
    void sing() {
        cout << "Mooou" << endl;
    }
};

static int example() {
    Cat tom;
    Dog *alice_address = new Dog();
    Cat team1[100];
    Dog team2[100];
    Cow team3[100];

    for (int i = 0; i < 100; i++) {
        team1[i].sing();
    }
    for (int i = 0; i < 100; i++) {
        team2[i].sing();
    }
    for (int i = 0; i < 100; i++) {
        team3[i].sing();
    }

    tom.sing();
    alice_address->sing(); // (*alice_address).sing()

    vector<Animal *> pack;

    for (int i = 0; i < 100; i++) {
        pack.push_back(new Cat());
        pack.push_back(new Dog());
        pack.push_back(new Cow());
    }

    for (int i = 0; i < pack.size(); i++) {
        pack[i]->sing();
    }

    Animal *a1 = new Cat(); // upcasting
    a1->sing();
}