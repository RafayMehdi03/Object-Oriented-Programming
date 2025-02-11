#include <iostream>
using namespace std;

class Smartphone {
private:
    string company;
    string model;
    string displayResolution;
    int ram;
    int rom;
    int storage;

public:
    void setCompany(const string& c) {
        company = c;
    }

    string getCompany() const {
        return company;
    }

    void setModel(const string& m) {
        model = m;
    }

    string getModel() const {
        return model;
    }

    void setDisplayResolution(const string& dr) {
        displayResolution = dr;
    }

    string getDisplayResolution() const {
        return displayResolution;
    }

    void setRam(int r) {
        ram = r;
    }

    int getRam() const {
        return ram;
    }

    void setRom(int r) {
        rom = r;
    }

    int getRom() const {
        return rom;
    }

    void setStorage(int s) {
        storage = s;
    }

    int getStorage() const {
        return storage;
    }

    void makePhoneCall() const {
        cout << "Making a phone call..." << endl;
    }

    void sendMessage() const {
        cout << "Sending a message..." << endl;
    }

    void connectToWifi() const {
        cout << "Connecting to WiFi..." << endl;
    }

    void browseInternet() const {
        cout << "Browsing the internet..." << endl;
    }
};

int main() {
    Smartphone phone1, phone2;

    phone1.setCompany("Apple");
    phone1.setModel("iPhone 13 Pro");
    phone1.setDisplayResolution("2532 x 1170");
    phone1.setRam(8);
    phone1.setRom(256);
    phone1.setStorage(256);

    phone2.setCompany("Samsung");
    phone2.setModel("Galaxy Note 20 Ultra");
    phone2.setDisplayResolution("2400 x 1080");
    phone2.setRam(8);
    phone2.setRom(256);
    phone2.setStorage(256);

    cout << "Phone 1 Details:" << endl;
    cout << "Company: " << phone1.getCompany() << endl;
    cout << "Model: " << phone1.getModel() << endl;
    cout << "Display Resolution: " << phone1.getDisplayResolution() << endl;
    cout << "RAM: " << phone1.getRam() << " GB" << endl;
    cout << "ROM: " << phone1.getRom() << " GB" << endl;
    cout << "Storage: " << phone1.getStorage() << " GB" << endl;

    cout << "Phone 2 Details:" << endl;
    cout << "Company: " << phone2.getCompany() << endl;
    cout << "Model: " << phone2.getModel() << endl;
    cout << "Display Resolution: " << phone2.getDisplayResolution() << endl;
    cout << "RAM: " << phone2.getRam() << " GB" << endl;
    cout << "ROM: " << phone2.getRom() << " GB" << endl;
    cout << "Storage: " << phone2.getStorage() << " GB" << endl;

    phone1.makePhoneCall();
    phone1.sendMessage();
    phone1.connectToWifi();
    phone1.browseInternet();

    return 0;
}
