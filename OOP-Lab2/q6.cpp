#include <iostream>
#include <string>
using namespace std;
struct Register {
    int courseId;
    string courseName;
};
struct Student{
    int studentId;
    string firstName;
    string lastName;
    string cellNo;
    string email;
    struct Register R ;
};
int main() {
    Student students[5];
    for (int i = 0; i < 5; ++i) {
        cout << "Enter details for student " << i + 1 << endl;
        cout << "Course ID: ";
        cin >> students[i].R.courseId;
        cin.ignore();
        cout << "Course Name: ";
        getline(cin, students[i].R.courseName);
        cout << "Student ID: ";
        cin >> students[i].studentId;
        cin.ignore();
        cout << "First Name: ";
        getline(cin, students[i].firstName);
        cout << "Last Name: ";
        getline(cin, students[i].lastName);
        cout << "Cell Number: ";
        getline(cin, students[i].cellNo);
        cout << "Email: ";
        getline(cin, students[i].email);
        cout << endl;
    }
    cout << "Student Information:" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "Student " << i + 1 << endl;
        cout << "Course ID: " << students[i].R.courseId << endl;
        cout << "Course Name: " << students[i].R.courseName << endl;
        cout << "Student ID: " << students[i].studentId << endl;
        cout << "First Name: " << students[i].firstName << endl;
        cout << "Last Name: " << students[i].lastName << endl;
        cout << "Cell Number: " << students[i].cellNo << endl;
        cout << "Email: " << students[i].email << endl;
    }
    return 0;
}
