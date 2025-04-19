#include <iostream>
#include <string>

using namespace std;

class Vehicle {
protected:
    string model;
    double rate;
public:
    virtual double getDailyRate() = 0;
    virtual void displayDetails() = 0;
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
    Car(string m, double r) {
        model = m;
        rate = r;
    }
    double getDailyRate() {
        return rate;
    }
    void displayDetails() {
        cout << "Car Model: " << model << ", Daily Rate: " << rate << endl;
    }
};

class Bike : public Vehicle {
public:
    Bike(string m, double r) {
        model = m;
        rate = r;
    }
    double getDailyRate() {
        return rate;
    }
    void displayDetails() {
        cout << "Bike Model: " << model << ", Daily Rate: " << rate << endl;
    }
};

int main() {
    Vehicle* v1 = new Car("Sedan", 60);
    Vehicle* v2 = new Bike("Mountain", 25);

    v1->displayDetails();
    cout << "Rate: " << v1->getDailyRate() << endl;

    v2->displayDetails();
    cout << "Rate: " << v2->getDailyRate() << endl;

    delete v1;
    delete v2;

    return 0;
}
