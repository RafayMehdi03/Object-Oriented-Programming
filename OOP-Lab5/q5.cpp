#include <iostream>
using namespace std;

class Engine {
    string engineType;
public:
    Engine(string type) : engineType(type) {}
    void display() {
        cout << "Engine Type: " << engineType << endl;
    }
};

class Wheels {
    int wheelSize;
public:
    Wheels(int size) : wheelSize(size) {}
    void display() {
        cout << "Wheel Size: " << wheelSize << " inches" << endl;
    }
};

class Headlights {
    string headlightType;
public:
    Headlights(string type) : headlightType(type) {}
    void display() {
        cout << "Headlight Type: " << headlightType << endl;
    }
};

class Steering {
    string steeringType;
public:
    Steering(string type) : steeringType(type) {}
    void display() {
        cout << "Steering Type: " << steeringType << endl;
    }
};

class Car {
    Engine engine;      // Composition
    Wheels wheels;      // Composition
    Headlights* headlights; // Aggregation
    Steering* steering; // Aggregation
public:
    Car(Engine eng, Wheels whl, Headlights* hld, Steering* str)
        : engine(eng), wheels(whl), headlights(hld), steering(str) {}
    void display() {
        engine.display();
        wheels.display();
        headlights->display();
        steering->display();
    }
};

int main() {
    Engine e("V8");
    Wheels w(18);
    Headlights h("LED");
    Steering s("Power Steering");
    Car car(e, w, &h, &s);
    car.display();
    return 0;
}