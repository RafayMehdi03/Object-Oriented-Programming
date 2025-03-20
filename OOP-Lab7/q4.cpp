#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    string id;
    string address;
    string phoneNumber;
    string email;

public:
    Person(string n, string i, string addr, string phone, string mail)
        : name(n), id(i), address(addr), phoneNumber(phone), email(mail) {}

    virtual void displayInfo() {
        cout << "Name: " << name << ", ID: " << id << endl;
    }
};

class Student : public Person {
private:
    string coursesEnrolled;
    double GPA;

public:
    Student(string n, string i, string addr, string phone, string mail, string courses, double gpa)
        : Person(n, i, addr, phone, mail), coursesEnrolled(courses), GPA(gpa) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Courses Enrolled: " << coursesEnrolled << ", GPA: " << GPA << endl;
    }
};

int main() {
    Person* student = new Student("John Doe", "S123", "123 Street", "123-4567", "john@mail.com", "Math, Science", 3.5);
    student->displayInfo();

    delete student;
    return 0;
}
