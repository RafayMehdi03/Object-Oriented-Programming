#include <iostream>

using namespace std;

class SmartDevice {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void getStatus() = 0;
    virtual ~SmartDevice() {}
};

class LightBulb : public SmartDevice {
private:
    bool isOn;
    int brightness;
public:
    LightBulb() {
        isOn = false;
        brightness = 100;
    }
    void turnOn() {
        isOn = true;
    }
    void turnOff() {
        isOn = false;
    }
    void getStatus() {
        cout << "LightBulb is " << (isOn ? "On" : "Off") << ", Brightness: " << brightness << "%" << endl;
    }
};

class Thermostat : public SmartDevice {
private:
    bool isOn;
    double temperature;
public:
    Thermostat() {
        isOn = false;
        temperature = 22.0;
    }
    void turnOn() {
        isOn = true;
    }
    void turnOff() {
        isOn = false;
    }
    void getStatus() {
        cout << "Thermostat is " << (isOn ? "On" : "Off") << ", Temperature: " << temperature << endl;
    }
};

int main() {
    LightBulb bulb;
    Thermostat thermo;

    bulb.turnOn();
    thermo.turnOn();

    bulb.getStatus();
    thermo.getStatus();

    bulb.turnOff();
    thermo.turnOff();

    bulb.getStatus();
    thermo.getStatus();

    return 0;
}
