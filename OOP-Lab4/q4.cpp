#include <iostream>
#include <string>

using namespace std;

class Car {
    int carID;
    string model;
    int year;
    bool isRented;

public:
    Car() {
        isRented = false;
    }

    Car(int id, string carModel, int carYear) {
        carID = id;
        model = carModel;
        year = carYear;
        isRented = false;
    }

    void rentCar() {
        if (!isRented) {
            isRented = true;
            cout << endl <<"Car rented successfully!" << endl;
        } else {
            cout << endl <<"Car is already rented!" << endl;
        }
    }

    void returnCar() {
        if (isRented) {
            isRented = false;
            cout << endl <<"Car returned successfully!" << endl;
        } else {
            cout << endl << "Car was not rented!" << endl;
        }
    }

    bool isVintage() {
        return year < 2000;
    }

    void displayCarInfo() {
        cout << endl << "Car ID: " << carID << ", Model: " << model << ", Year: " << year
             << ", Rented: " << (isRented ? "Yes" : "No") << endl;
    }
};

int main() {
    Car car1(101, "Toyota Corolla", 1999);
    Car car2(102, "Honda Civic", 2005);
    Car car3(103, "Ford Mustang", 1965);

    car1.displayCarInfo();
    car2.displayCarInfo();
    car3.displayCarInfo();

    car1.rentCar();
    car2.rentCar();
    car3.rentCar();

    car1.displayCarInfo();
    car2.displayCarInfo();
    car3.displayCarInfo();

    car1.returnCar();
    car2.returnCar();

    car1.displayCarInfo();
    car2.displayCarInfo();
    car3.displayCarInfo();

    cout << "Is car1 vintage? " << (car1.isVintage() ? "Yes" : "No") << endl;
    cout << "Is car3 vintage? " << (car3.isVintage() ? "Yes" : "No") << endl;

    return 0;
}
