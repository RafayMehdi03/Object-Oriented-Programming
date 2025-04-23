#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    float gpa;
};

int main() {
    Student students[5];
    ofstream outFile("students.txt", ios::out);
    for (int i = 0; i < 5; i++) {
        cin >> students[i].id >> students[i].name >> students[i].gpa;
        outFile << students[i].id << " " << students[i].name << " " << students[i].gpa << endl;
    }
    outFile.close();

    Student extra;
    ofstream appendFile("students.txt", ios::app);
    cin >> extra.id >> extra.name >> extra.gpa;
    appendFile << extra.id << " " << extra.name << " " << extra.gpa << endl;
    appendFile.close();

    Student readStudent;
    ifstream inFile("students.txt");
    while (inFile >> readStudent.id >> readStudent.name >> readStudent.gpa) {
        cout << readStudent.id << " " << readStudent.name << " " << readStudent.gpa << endl;
    }
    inFile.close();
    return 0;
}