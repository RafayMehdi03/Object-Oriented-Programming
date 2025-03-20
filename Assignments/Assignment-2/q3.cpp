#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string vehicleID;
    double speed;
    double capacity;
    double efficiency;
    static int totalDeliveries;
public:
    Vehicle(string id, double spd, double cap, double eff) : vehicleID(id), speed(spd), capacity(cap), efficiency(eff) {
        totalDeliveries++;
    }
    virtual void calculateRoute() {
        cout << "Calculating route for " << vehicleID << endl;
    }
    virtual double estimateDeliveryTime() {
        return 10.0;
    }
    static int getTotalDeliveries() {
        return totalDeliveries;
    }
    bool operator==(const Vehicle& other) {
        return (speed == other.speed && capacity == other.capacity && efficiency == other.efficiency);
    }
    friend void resolveConflict(Vehicle &v1, Vehicle &v2);
};
int Vehicle::totalDeliveries = 0;
class RamzanDrone : public Vehicle {
public:
    RamzanDrone(string id, double spd, double cap, double eff) : Vehicle(id, spd, cap, eff) {}
    void calculateRoute() override {
        cout << "Aerial route for Drone " << vehicleID << endl;
    }
    double estimateDeliveryTime() override {
        return 5.0;
    }
    void command(string action, string packageID) {
        cout << "Drone " << vehicleID << " delivering " << packageID << endl;
    }
    void command(string action, string packageID, string urgencyLevel) {
        if (urgencyLevel == "urgent") {
            cout << "Drone " << vehicleID << " speeding up to deliver " << packageID << endl;
        } else {
            command(action, packageID);
        }
    }
};
class RamzanTimeShip : public Vehicle {
public:
    RamzanTimeShip(string id, double spd, double cap, double eff) : Vehicle(id, spd, cap, eff) {}
    void calculateRoute() override {
        cout << "Historical route for TimeShip " << vehicleID << "..." << endl;
    }
    double estimateDeliveryTime() override {
        return 15.0;
    }
    void command(string action, string packageID) {
        cout << "TimeShip " << vehicleID << " delivering " << packageID << endl;
    }
    void command(string action, string packageID, string urgencyLevel) {
        if (urgencyLevel == "urgent") {
            cout << "TimeShip " << vehicleID << " checking historical consistency before delivering " << packageID << endl;
        } else {
            command(action, packageID);
        }
    }
};
class RamzanHyperPod : public Vehicle {
public:
    RamzanHyperPod(string id, double spd, double cap, double eff) : Vehicle(id, spd, cap, eff) {}
    void calculateRoute() override {
        cout << "Underground route for HyperPod " << vehicleID << "..." << endl;
    }
    double estimateDeliveryTime() override {
        return 12.0;
    }
    void command(string action, string packageID) {
        cout << "HyperPod " << vehicleID << " delivering " << packageID << endl;
    }
    void command(string action, string packageID, string urgencyLevel) {
        cout << "HyperPod " << vehicleID << " delivering bulk package " << packageID << endl;
    }
};
void resolveConflict(Vehicle &v1, Vehicle &v2) {
    if (v1.efficiency > v2.efficiency) {
        cout << "Vehicle " << v1.vehicleID << " is chosen for the delivery due to higher efficiency." << endl;
    } else {
        cout << "Vehicle " << v2.vehicleID << " is chosen for the delivery due to higher efficiency." << endl;
    }
}
int main() {
    RamzanDrone drone("D1", 200, 10, 80);
    RamzanTimeShip timeShip("T1", 50, 5, 70);
    RamzanHyperPod hyperPod("H1", 120, 50, 90);
    drone.command("Deliver", "P001", "urgent");
    timeShip.command("Deliver", "P002", "normal");
    hyperPod.command("Deliver", "P003", "urgent");
    resolveConflict(drone, hyperPod);
    if (drone == hyperPod) {
        cout << "Drone and HyperPod have same speed/efficieny/capacity !" << endl;
    } else {
        cout << "Drone and HyperPod have different speed/efficieny/capacity !" << endl;
    }
    cout << "Total Deliveries: " << Vehicle::getTotalDeliveries() << endl;
    return 0;
}