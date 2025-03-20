#include <iostream>
#include <string>
using namespace std;

class User {
protected:
    string name;
    int id;
    bool isRegistered;
    bool hasPaid;
    int stopId;
    bool assignedToBus;

public:
    User(string name, int id)
        : name(name), id(id), isRegistered(false), hasPaid(false), stopId(-1), assignedToBus(false) {}

    string getName() {
        return name;
    }

    int getId() {
        return id;
    }

    void registerUser() {
        isRegistered = true;
    }

    virtual void payFees() {
        hasPaid = true;
    }

    bool checkRegistrationStatus() {
        return isRegistered && hasPaid;
    }

    void setStopId(int stopId) {
        this->stopId = stopId;
    }

    int getStopId() {
        return stopId;
    }

    bool isAssignedToBus() {
        return assignedToBus;
    }

    void assignToBus() {
        assignedToBus = true;
    }
};

class Student : public User {
public:
    Student(string name, int id) : User(name, id) {}

    void payFees() override {
        cout << name << " (Student) has paid the semester fee." << endl;
        hasPaid = true;
    }
};

class Teacher : public User {
public:
    Teacher(string name, int id) : User(name, id) {}

    void payFees() override {
        cout << name << " (Teacher) has paid the monthly fee." << endl;
        hasPaid = true;
    }
};

class Staff : public User {
public:
    Staff(string name, int id) : User(name, id) {}

    void payFees() override {
        cout << name << " (Staff) has paid the monthly fee." << endl;
        hasPaid = true;
    }
};

class Bus {
private:
    int busId;
    int stops[10];
    int numStops;
    User* passengers[50];
    int numStudents;

public:
    Bus(int busId) : busId(busId), numStops(0), numStudents(0) {}

    void addStop(int stopId) {
        if (numStops < 10) {
            stops[numStops] = stopId;
            numStops++;
        }
    }

    bool assignUserToBus(User& user) {
        if (user.checkRegistrationStatus() && numStudents < 50) {
            for (int i = 0; i < numStops; i++) {
                if (stops[i] == user.getStopId()) {
                    user.assignToBus();
                    passengers[numStudents] = &user;
                    numStudents++;
                    cout << user.getName() << "(ID -- " << user.getId() << ") has been assigned to bus with bus ID " << busId << endl;
                    return true;
                }
            }
        }
        return false;
    }

    bool operator==(const Bus& other) const {
        if (this->busId != other.busId) return false;

        if (this->numStops != other.numStops) return false;

        for (int i = 0; i < this->numStops; i++) {
            bool stopFound = false;
            for (int j = 0; j < other.numStops; j++) {
                if (this->stops[i] == other.stops[j]) {
                    stopFound = true;
                    break;
                }
            }
            if (!stopFound) return false;
        }

        return true;
    }

    void displayBusDetails() {
        cout << "Bus ID: " << busId << " | Stops: ";
        for (int i = 0; i < numStops; i++) {
            cout << stops[i] << " ";
        }
        cout << endl;
    }

    void displayPassengers() {
        cout << "Bus " << busId << " has the following passengers: " << endl;
        for (int i = 0; i < numStudents; i++) {
            cout << passengers[i]->getName() << " (ID: " << passengers[i]->getId() << ")" << endl;
        }
    }
};

int main() {
    Student student1("Ali Raza", 866);
    Student student2("Sibtain Hanif",494);
    Teacher teacher1("Fatima Jamil", 312);
    Staff staff1("Ahmed Shahid", 232);
    student1.registerUser();
    student1.payFees();
    student1.setStopId(1);
    student2.registerUser();
    student2.payFees();
    student2.setStopId(4);
    teacher1.registerUser();
    teacher1.payFees();
    teacher1.setStopId(2);
    staff1.registerUser();
    staff1.payFees();
    staff1.setStopId(3);
    Bus bus1(1001);
    Bus bus2(1002);
    bus1.addStop(1);
    bus1.addStop(2);
    bus2.addStop(2);
    bus2.addStop(3);
    bus1.displayBusDetails();
    bus2.displayBusDetails();
    bus1.assignUserToBus(student1);
    bus1.assignUserToBus(student2);
    bus2.assignUserToBus(teacher1);
    bus2.assignUserToBus(staff1);
    bus1.displayPassengers();
    bus2.displayPassengers();
    if (bus1 == bus2) {
        cout << "Bus 1 and Bus 2 are the same." << endl;
    } else {
        cout << "Bus 1 and Bus 2 are not the same." << endl;
    }
}