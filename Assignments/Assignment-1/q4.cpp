#include <iostream>
#include <string>
using namespace std;
class Student {
private:
    string name;
    int id;
    bool isRegistered;
    bool hasPaid;
    int stopId;
    bool assignedToBus;
public:
    Student(string name, int id) 
        : name(name), id(id), isRegistered(false), hasPaid(false), stopId(-1), assignedToBus(false) {}
    string getName(){
        return name ;
    }
    int getId(){
        return id ;
    }
    void registerStudent() {
        isRegistered = true;
    }
    void payFees() {
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
class Bus {
private:
    int busId;
    int stops[10];
    int numStops;
public:
    Bus(int busId) : busId(busId), numStops(0) {}
    void addStop(int stopId) {
        if (numStops < 10) {
            stops[numStops] = stopId;
            numStops++;
        }
    }
    bool assignStudentToBus(Student &student) {
        if(student.checkRegistrationStatus()){
        for (int i = 0; i < numStops; i++) {
            if (stops[i] == student.getStopId()) {
                student.assignToBus();
                cout << student.getName() << "(ID -- " << student.getId() << ") has been assigned to bus with bus ID " << busId << endl ;
                return true;
            }
        }
        }
        return false;      
    }
    void displayBusDetails() {
        cout << "Bus ID: " << busId << " | Stops: ";
        for (int i = 0; i < numStops; i++) {
            cout << stops[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    Student student1("Rafay Mehdi", 1);
    Student student2("Mohsin Naqvi", 2);
    student1.registerStudent();
    student1.payFees();
    student1.setStopId(1);  
    student2.registerStudent();
    student2.setStopId(2);  
    Bus bus1(1001);
    Bus bus2(1002);
    bus1.addStop(1);
    bus1.addStop(3);
    bus2.addStop(2);
    bus2.addStop(4);
    bus1.displayBusDetails();
    bus2.displayBusDetails();
    if(bus1.assignStudentToBus(student1))
        student1.assignToBus() ;
    else
        cout << student1.getName() << " is not registered or has not paid the semester fee" << endl ;
    if(bus2.assignStudentToBus(student2)) // will fail because hasn't paid fees
        student2.assignToBus() ;
    else
        cout << student2.getName() << " is not registered or has not paid the semester fee" << endl ;
}