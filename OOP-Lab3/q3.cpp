#include <iostream>
using namespace std;

class Object {
private:
    static int count;
    int serialNumber;

public:
    Object() {
        count++;
        serialNumber = count;
    }

    void reportSerialNumber() const {
        cout << "I am object number " << serialNumber << endl;
    }
};

int Object::count = 0;

int main() {
    Object obj1, obj2, obj3;

    obj1.reportSerialNumber();
    obj2.reportSerialNumber();
    obj3.reportSerialNumber();

    return 0;
}
