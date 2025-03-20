#include <iostream>
#include <string>
using namespace std;

class Ghost {
protected:
    string nameofWorker;
    int scareLevel;
public:
    Ghost(string name, int level) : nameofWorker(name), scareLevel(level) {}

    virtual void performHaunting() {
        cout << nameofWorker << " performed haunting at scare level - " << scareLevel << endl;
    }

    friend ostream& operator<<(ostream& os, const Ghost& ghost) {
        os << "Ghost played by: " << ghost.nameofWorker << ", Scare Level: " << ghost.scareLevel;
        return os;
    }

    Ghost operator +(const Ghost& other) {
        string newName = this->nameofWorker + " and " + other.nameofWorker;
        int levelScare = this->scareLevel + other.scareLevel;
        if (levelScare > 10) {
            levelScare = 10;
        }
        return Ghost(newName, levelScare);
    }

    string getName() const {
        return nameofWorker;
    }

    int getscareLevel() const {
        return scareLevel;
    }
};

class Poltergeists : public Ghost {
public:
    Poltergeists(string name, int level) : Ghost(name, level) {}

    void performHaunting() override {
        cout << nameofWorker << " is moving objects" << endl;
    }
};

class Banshees : public Ghost {
public:
    Banshees(string name, int level) : Ghost(name, level) {}

    void performHaunting() override {
        cout << nameofWorker << " is screaming loudly" << endl;
    }
};

class ShadowGhosts : public Ghost {
public:
    ShadowGhosts(string name, int level) : Ghost(name, level) {}

    void performHaunting() override {
        cout << nameofWorker << " is whispering creepily" << endl;
    }
};

class ShadowPoltergeists : public ShadowGhosts, public Poltergeists {
public:
    ShadowPoltergeists(string n, int level) : ShadowGhosts(n, level), Poltergeists(n, level) {}

    void performHaunting() override {
        cout << ShadowGhosts::nameofWorker << " is moving objects and whispering creepily" << endl;
    }
};

class HauntedHouse {
    string name;
    Ghost* ghosts[5];  // Array of pointers to Ghost objects
    int numGhosts;

public:
    HauntedHouse(string n) : name(n), numGhosts(0) {}

    void addGhost(Ghost* ghost) {
        if (numGhosts < 5) {
            ghosts[numGhosts++] = ghost;
            cout << ghost->getName() << " is added to " << name << endl;
        } else {
            cout << "No space left" << endl;
        }
    }

    int getnumGhosts() const {
        return numGhosts;
    }

    int getGhostLevel(int index) const {
        return ghosts[index]->getscareLevel();
    }

    string getGhostName(int index) const {
        return ghosts[index]->getName();
    }
};

class Visitor {
    string name;
    int bravery;

public:
    Visitor(string n, int b) : name(n), bravery(b) {}

    string getBraveryRange() {
        if (bravery > 0 && bravery <= 4) {
            return "Cowardly";
        } else if (bravery >= 5 && bravery <= 7) {
            return "Average";
        } else if (bravery >= 8 && bravery <= 10) {
            return "Fearless";
        } else {
            return "Invalid bravery";
        }
    }

    void haunt(const HauntedHouse& House) {
        for (int i = 0; i < House.getnumGhosts(); i++) {
            int check = House.getGhostLevel(i);
            if (check > 0 && check < 11) {
                if (bravery > check) {
                    cout << House.getGhostName(i) << " makes " << name << " laugh or taunt the ghost" << endl;
                } else if (bravery == check) {
                    cout << name << " gets a shaky voice due to " << House.getGhostName(i) << endl;
                } else {
                    cout << House.getGhostName(i) << " makes " << name << " scream and run away" << endl;
                }
            } else {
                cout << House.getGhostName(i) << " has invalid bravery" << endl;
            }
        }
    }

    string getName() {
        return name;
    }

    friend void Visit(Visitor visitors[5], const HauntedHouse& h);
};

void Visit(Visitor visitors[5], const HauntedHouse& h) {
    for (int i = 0; i < 5; i++) {
        cout << visitors[i].getName() << "'s Visit: " << endl;
        visitors[i].haunt(h);
        cout << endl;
    }
}

int main() {
    HauntedHouse hauntedHouse1("Spooky Mansion");
    HauntedHouse hauntedHouse2("Haunted Castle");

    Poltergeists ghost1("Poltergeist A", 4);
    Banshees ghost2("Banshee B", 7);
    ShadowGhosts ghost3("ShadowGhost C", 5);
    ShadowPoltergeists ghost4("ShadowPoltergeist D", 6);
    Poltergeists ghost5("Poltergeist E", 3);

    hauntedHouse1.addGhost(&ghost1);
    hauntedHouse1.addGhost(&ghost2);
    hauntedHouse1.addGhost(&ghost3);

    hauntedHouse2.addGhost(&ghost2);
    hauntedHouse2.addGhost(&ghost5);

    Visitor visitors[5] = {
        Visitor("Saim", 3),    // Cowardly
        Visitor("Huzaifa", 6), // Average
        Visitor("Nadeem", 8),  // Fearless
        Visitor("Aamer", 4),   // Cowardly
        Visitor("Rafay", 9)    // Fearless
    };

    cout << "For 1st Haunted House: " << endl;
    Visit(visitors, hauntedHouse1);
    cout << "For 2nd Haunted House: " << endl;
    Visit(visitors, hauntedHouse2);

    return 0;
}
