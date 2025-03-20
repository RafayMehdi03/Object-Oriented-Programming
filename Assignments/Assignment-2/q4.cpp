#include <iostream>
#include <string>
using namespace std;

int hashPassword(string password) {
    int hash = 5381;
    for (char c : password) {
        hash = hash * 33 + c;
    }
    return hash;
}

class User {
protected:
    string name;
    string id;
    string email;
    int hashed_password;
    string permissions[3];

public:
    User(string name, string id, string email, string password) {
        this->name = name;
        this->id = id;
        this->email = email;
        this->hashed_password = hashPassword(password);
    }

    virtual void display() {
        cout << "Name: " << name << "\nID: " << id << "\nEmail: " << email << "\nPermissions: ";
        for (int i = 0; i < 3; i++) {
            if (permissions[i] != "") {
                cout << permissions[i] << " ";
            }
        }
        cout << endl;
    }

    string getName() {
        return name;
    }

    bool authenticate(string password) {
        return hashed_password == hashPassword(password);
    }

    virtual void accessLab() = 0;

    virtual void performAction(string action) {
        cout << "Action not allowed for this user." << endl;
    }
};

class Student : public User {
protected:
    int assignments[5];

public:
    Student() : User("", "", "", "") {
        for (int i = 0; i < 5; i++) {
            assignments[i] = -1;
        }
        permissions[0] = "submit assignment";
        permissions[1] = "";
        permissions[2] = "";
    }

    Student(string name, string id, string email, string password)
        : User(name, id, email, password) {
        for (int i = 0; i < 5; i++) {
            assignments[i] = -1;
        }
        permissions[0] = "submit assignment";
        permissions[1] = "";
        permissions[2] = "";
    }

    void display() override {
        cout << "Student Name: " << name << "\nStudent ID: " << id << "\nEmail: " << email << endl;
        cout << "Assignments Status: ";
        cout << endl ;
        for (int i = 0; i < 5; i++) {
            if (assignments[i] == -1) {
                cout << "No Assignment " << endl ;
            } else if (assignments[i] == 1) {
                cout << "Submitted "<< endl ;
            } else {
                cout << "Not Submitted "<< endl ;
            }
        }
    }

    void submitAssignment(int index) {
        if (index >= 0 && index < 5 && assignments[index] != -1) {
            assignments[index] = 1;
        }
    }

    void accessLab() override {
        cout << "Student can only submit assignments." << endl;
    }

    void performAction(string action) override {
        if (action == "submit assignment") {
            int assignmentIndex;
            cout << "Enter the assignment index to submit (0-4): ";
            cin >> assignmentIndex;
            if (assignmentIndex >= 0 && assignmentIndex < 5 && assignments[assignmentIndex] != -1) {
                submitAssignment(assignmentIndex);
                cout << "Assignment " << assignmentIndex << " submitted." << endl;
            } else {
                cout << "Invalid assignment index or no assignment assigned." << endl;
            }
        } else {
            User::performAction(action);
        }
    }

    void addAssignment(int index) {
        if (index >= 0 && index < 5 && assignments[index] == -1) {
            assignments[index] = 0;
            cout << "Assignment " << index << " added." << endl;
        } else {
            cout << "Assignment index is invalid or assignment already exists." << endl;
        }
    }
};

class TA : public Student {
private:
    Student studentsAssigned[10];
    int studentCount;

public:
    TA(string name, string id, string email, string password)
        : Student(name, id, email, password), studentCount(0) {
        permissions[0] = "view projects";
        permissions[1] = "manage students";
        permissions[2] = "";
    }

    void display() override {
        cout << "TA Name: " << name << "\nTA ID: " << id << "\nEmail: " << email << endl;
        cout << "Students Assigned: " << studentCount << endl;
        for (int i = 0; i < studentCount; i++) {
            cout << "Student " << i + 1 << ": " << studentsAssigned[i].getName() << endl;
        }
    }

    void assignStudent(Student newStudent) {
        if (studentCount < 10) {
            studentsAssigned[studentCount] = newStudent;
            studentCount++;
            cout << "Student assigned to TA." << endl;
        } else {
            cout << "Cannot assign more than 10 students to TA." << endl;
        }
    }

    void accessLab() override {
        cout << "TA can view projects and manage students." << endl;
    }

    void performAction(string action) override {
        if (action == "assign student") {
            Student newStudent("Ali", "S001", "ali@university.com", "password123");
            assignStudent(newStudent);
        } else {
            Student::performAction(action);
        }
    }
};

class Professor : public User {
public:
    Professor(string name, string id, string email, string password)
        : User(name, id, email, password) {}

    void display() override {
        cout << "Professor Name: " << name << "\nProfessor ID: " << id << "\nEmail: " << email << endl;
    }

    void assignProject() {
        cout << "Professor assigning projects." << endl;
    }

    void accessLab() override {
        cout << "Professor has full access to the lab." << endl;
    }

    void performAction(string action) override {
        if (action == "assign project") {
            assignProject();
        } else {
            User::performAction(action);
        }
    }
};

void authenticateAndPerformAction(User* user, string action, string password) {
    if (user->authenticate(password)) {
        user->performAction(action);
    } else {
        cout << "Authentication failed!" << endl;
    }
}

int main() {
    Student sana("Sana", "S123", "sana@university.com", "password123");
    TA ahmed("Ahmed", "T456", "ahmed@university.com", "password123");
    Professor drImran("Dr. Imran", "P789", "imran@university.com", "password123");

    sana.display();
    cout << endl ;
    ahmed.display();
    cout << endl ;
    drImran.display();
    cout << endl ;
    sana.addAssignment(0);
    sana.addAssignment(1);
    cout << endl ;
    sana.display();
    cout << endl ;
    string password = "password123";
    authenticateAndPerformAction(&sana, "submit assignment", password);
    sana.display() ;
    cout << endl ;
    authenticateAndPerformAction(&ahmed, "assign student", password);
    ahmed.display() ;
    cout << endl ;
    authenticateAndPerformAction(&drImran, "assign project", password);

    return 0;
}