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
    
    
    // x.op<(y) = true   iif   x < y
    bool operator<(const Hobbit & other) const {
        if (this->height < other.height) {
            return true;
        } else {
            return false;
        }
    }    
};



int main_h1(int argc, char * argv[]) {
    Hobbit * h1 = new Hobbit("Froddo", 145);
    Hobbit * h2 = new Hobbit("Sam", 150);
    Hobbit * h3 = new Hobbit("Bildo", 140);
    
    set<Hobbit> team;
//    set<Hobbit>* team = new set<Hobbit>();
    
    team.insert(*h1);
    team.insert(*h2);
    team.insert(*h3);
    
    set<Hobbit>::iterator p = team.begin();
    
    int i =0;
    while (p != team.end()) {
        cout << ++i << ". " << p->name << " " << p->height << endl;
        p++;
    }
            
    delete h1;
    delete h2;
    delete h3;
    
    return 0;
}

