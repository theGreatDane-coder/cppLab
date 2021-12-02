#include <iostream>
#include <set>

using namespace std;

class Hobbit {
public:
    string name;
    int height;

    Hobbit(string name, int height) : name(name), height(height) {
        cout << "A new hobbit has been created with name " << name << endl;
    }

    Hobbit(const Hobbit& other) : name(other.name), height(other.height) {
        cout << "A new hobbit has been copy-created with name " << name << endl;
    }

    ~Hobbit() {
        cout << "Hobbit has been destroyed with name " << name << endl;
    }
};

class HobbitHeightCompator {
public:

    bool operator()(const Hobbit& left, const Hobbit& right) const {
        if (left.height < right.height) {
            return true;
        } else {
            return false;
        }
    }
};

class HobbitNameCompator {
public:

    bool operator()(const Hobbit& left, const Hobbit& right) const {
        if (left.name < right.name) {
            return true;
        } else {
            return false;
        }
    }
};

int main_h2(int argc, char * argv[]) {
    Hobbit * h1 = new Hobbit("Froddo", 145);
    Hobbit * h2 = new Hobbit("Sam", 150);
    Hobbit * h3 = new Hobbit("Bildo", 140);

    set<Hobbit, HobbitNameCompator> teamA;
    set<Hobbit, HobbitHeightCompator> teamB;

    teamA.insert(*h1);
    teamA.insert(*h2);
    teamA.insert(*h3);

    teamB.insert(*h1);
    teamB.insert(*h2);
    teamB.insert(*h3);


    set<Hobbit>::iterator p = teamA.begin();

    int i = 0;
    while (p != teamA.end()) {
        cout << ++i << ". " << p->name << " " << p->height << endl;
        p++;
    }




    delete h1;
    delete h2;
    delete h3;

    return 0;
}

