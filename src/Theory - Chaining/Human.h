#include <string>

using namespace std;

class Human {
private:
    int age;

public:
    string name;
    int energy;

    Human(string name, int age) : name(name), energy(5), age(age) {
    }

    Human& jogging() {
        energy--;
        return *this;
    }

    Human &sleep() {
        energy = 10;
        return *this;
    }

    Human &eat() {
        energy += 3;
        return *this;
    }

    int getAge() {
        return age;
    }

    int &getAgeReference() {
        return age;
    }
};

// int f( int x, int y ){
//     int sum = x+y;
//     cout << sum;
//     return sum;
// }

// f(1,3);

int example() {
    Human h1("Bob", 10);
    Human h2("Eva", 20);

    Human &qwe = h1;

    Human *p = &h1;

    Human cpy = h1;

    h1.jogging();
    h1.jogging();
    h1.eat();
    h1.sleep();
    h1.jogging();
    qwe.jogging();
    p->jogging();
    (*p).jogging();

    // x = h1.jogging();
    // jogging();

    Human &c = h1.jogging();

    h1.jogging().jogging().eat().sleep().jogging().eat();

    {
        int age = h1.getAge();
        age++;

        h1.getAge();
    }

    {
        int age = h1.getAgeReference();
        age++;
    }

    {
        int &age = h1.getAgeReference();
        age++;
    }

    {
        // h1.getAge()++; // error
    }

    {
        (h1.getAgeReference())++;
    }
}