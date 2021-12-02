#include <iostream>
#include <string>

using namespace std;

class Human {
private:
    string name;
    int happiness;
    int social;

public:
    Human(string name) : name(name), happiness(5), social(5) {
    }

    string getName() const {
        return name;
    }

    void sayHelloTo(/*const*/ Human &other) /*const*/ {
        this->social++;
        other.happiness++;
    }

    void sayHelloTo(Human *other) {
        this->social++;
        other->happiness++;
    }

    void talkTo(const Human &other) {
        this->social++;
    }

    void lookAt(const Human &other) const {
    }

    void giveGiftTo(Human &other) const {
        other.happiness++;
    }

    void operator+(/*const*/ Human &other) /*const*/ {
        this->social++;
        other.happiness++;
    }

    string operator*() {
        return name;
    }
};

void example() {
    Human h1("Bob");
    Human h2("Alice");

    h1.sayHelloTo(h2);

    h1.sayHelloTo(&h2);

    h2.sayHelloTo(h1);

    h1 + h2; // h1.operator+(h2);

    cout << *h1;


    cout << h1;
    // h2.happiness = ?
}