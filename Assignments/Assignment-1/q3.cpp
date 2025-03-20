#include <iostream>
#include <string>
using namespace std;
class User {
private:
    string name;
    int age;
    string licenseType;
    string contactInfo;
    int userID;
public:
    void registerUser() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter License Type (Learner/Intermediate/Full): ";
        cin >> licenseType;
        cout << "Enter Contact Info: ";
        cin >> contactInfo;
        cout << "Enter User ID: ";
        cin >> userID;
    }
    void updateUser() {
        cout << "Update Name: ";
        cin >> name;
        cout << "Update Age: ";
        cin >> age;
        cout << "Update License Type: ";
        cin >> licenseType;
        cout << "Update Contact Info: ";
        cin >> contactInfo;
    }
    string getLicenseType() {
        return licenseType;
    }
};
class Vehicle {
private:
    string model;
    double rentalPrice;
    string eligibility;

public:
    Vehicle(string m, double price, string elig) {
        model = m;
        rentalPrice = price;
        eligibility = elig;
    }

    void displayVehicle() {
        cout << "Model: " << model << ", Price: " << rentalPrice << ", Required License: " << eligibility << endl;
    }

    string getModel() {
        return model;
    }

    string getEligibility() {
        return eligibility;
    }

    double getRentalPrice() {
        return rentalPrice;
    }
};
int main() {
    int numVehicles;
    cout << "Enter number of vehicles: ";
    cin >> numVehicles;
    Vehicle* vehicles[numVehicles];
    for (int i = 0; i < numVehicles; i++) {
        string model, eligibility;
        double price;
        cout << "Enter Model: ";
        cin >> model;
        cout << "Enter Rental Price: ";
        cin >> price;
        cout << "Enter Required License Type: ";
        cin >> eligibility;
        vehicles[i] = new Vehicle(model, price, eligibility);
    }
    User user;
    user.registerUser();
    cout << "Available Vehicles:\n";
    for (int i = 0; i < numVehicles; i++) {
        vehicles[i]->displayVehicle();
    }
    string chosenModel;
    cout << "Enter the model you want to rent: ";
    cin >> chosenModel;
    bool rented = false;
    for (int i = 0; i < numVehicles; i++) {
        if (vehicles[i]->getModel() == chosenModel) {
            if (user.getLicenseType() == vehicles[i]->getEligibility()) {
                cout << "Rental successful! You rented " << vehicles[i]->getModel() << " for $" << vehicles[i]->getRentalPrice() << " per day." << endl;
                rented = true;
            } else {
                cout << "You are not eligible to rent this vehicle." << endl;
            }
            break;
        }
    }
    if (!rented) {
        cout << "Vehicle not found." << endl;
    }
    for (int i = 0; i < numVehicles; i++) {
        delete vehicles[i];
    }
    return 0;
}