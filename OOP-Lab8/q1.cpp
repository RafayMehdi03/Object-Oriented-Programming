#include <iostream>
using namespace std;

class Light;
class Fan;
class AirConditioner;
class SecuritySystem;

class User {
private:
    string id, role;
    int permission_level;

public:
    User(string user_id, string user_role, int access_level) : id(user_id), role(user_role), permission_level(access_level) {}

    void show_accessible_devices() const;

    friend class SecuritySystem;
};

class Device {
protected:
    string device_id, type;
    double power;

public:
    Device(string id, string device_type, double power_rating) : device_id(id), type(device_type), power(power_rating) {}

    virtual void turn_on() const = 0;

    virtual double calculate_power_usage(int hours) const {
        return power * hours;
    }

    friend ostream& operator<<(ostream &out, const Device &device) {
        out << device.type << " [ID: " << device.device_id << "]";
        return out;
    }
};

class Light : public Device {
public:
    Light(string id, string device_type, double power_rating) : Device(id, device_type, power_rating) {}

    void turn_on() const override {
        cout << *this << " is now ON.\n";
    }
};

class Fan : public Device {
private:
    int speed;

public:
    Fan(string id, string device_type, double power_rating, int fan_speed) : Device(id, device_type, power_rating), speed(fan_speed) {}

    void turn_on() const override {
        cout << *this << " is running at speed " << speed << ".\n";
    }

    double calculate_power_usage(int hours) const override {
        return power * speed * hours;
    }
};

class AirConditioner : public Device {
private:
    int temp_setting;

public:
    AirConditioner(string id, string device_type, double power_rating, int temperature) : Device(id, device_type, power_rating), temp_setting(temperature) {}

    void turn_on() const override {
        cout << *this << " is cooling to " << temp_setting << "°C.\n";
    }

    double calculate_power_usage(int hours) const override {
        return (power * hours) * (1 + (25 - temp_setting) * 0.02);
    }
};

class SecuritySystem : public Device {
public:
    SecuritySystem(string id, string device_type, double power_rating) : Device(id, device_type, power_rating) {}

    void turn_on() const override {
        cout << *this << " is now activated.\n";
    }

    double calculate_power_usage(int hours) const override {
        return power * hours * 1.5;
    }

    void view_logs(const User &user) const {
        if (user.permission_level >= 2) {
            cout << user.id << " - Security Logs:\n";
            cout << "- Intrusion detected at 3:00 AM\n- System reset needed\n";
        } else {
            cout << user.id << " does not have permission to view security logs.\n";
        }
    }
};

void User::show_accessible_devices() const {
    cout << "User: " << id << " - Accessible Devices:\n";
    cout << "- LED Light\n- Ceiling Fan\n- Air Conditioner\n";
    if (permission_level >= 2) {
        cout << "- Security System (Restricted)\n";
    }
}

int main() {
    User user1("User001", "Regular", 1);
    User user2("User002", "Admin", 2);

    Light light1("L001", "LED Light", 10);
    Fan fan1("F001", "Ceiling Fan", 50, 4);
    AirConditioner ac1("AC001", "Air Conditioner", 100, 26);
    SecuritySystem sec_sys1("S001", "Security System", 30);

    light1.turn_on();
    fan1.turn_on();
    ac1.turn_on();
    sec_sys1.turn_on();

    cout << "\nPower Usage:\n";
    cout << "LED Light: " << light1.calculate_power_usage(5) << " Watts\n";
    cout << "Ceiling Fan: " << fan1.calculate_power_usage(3) << " Watts\n";
    cout << "Air Conditioner: " << ac1.calculate_power_usage(6) << " Watts\n";
    cout << "Security System: " << sec_sys1.calculate_power_usage(24) << " Watts\n\n";

    user1.show_accessible_devices();  // Correct function call
    sec_sys1.view_logs(user2);        // Correct function call, view logs on SecuritySystem object

    return 0;
}
