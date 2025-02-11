#include <iostream>

using namespace std;

struct student {
    int m1, m2, m3;
    float avg;
    int total;
    char grade;
};

int main() {
    int count, i;

    cout << "Enter the number of students: ";
    cin >> count;

    struct student S[count];

    for (i = 0; i < count; i++) {
        cout << "Enter marks of student " << i + 1 << " for Maths: ";
        cin >> S[i].m1;

        cout << "Enter marks of student " << i + 1 << " for English: ";
        cin >> S[i].m2;

        cout << "Enter marks of student " << i + 1 << " for Science: ";
        cin >> S[i].m3;

        S[i].total = S[i].m1 + S[i].m2 + S[i].m3;
        S[i].avg = S[i].total / 3.0;

        if (S[i].avg >= 90) {
            S[i].grade = 'A';
        } else if (S[i].avg >= 80 && S[i].avg < 90) {
            S[i].grade = 'B';
        } else if (S[i].avg >= 70 && S[i].avg < 80) {
            S[i].grade = 'C';
        } else if (S[i].avg >= 60 && S[i].avg < 70) {
            S[i].grade = 'D';
        } else {
            S[i].grade = 'F';
        }
    }

    for (i = 0; i < count; i++) {
        cout << "Student " << i + 1 << endl;
        cout << "Maths Marks: " << S[i].m1 << endl;
        cout << "English Marks: " << S[i].m2 << endl;
        cout << "Science Marks: " << S[i].m3 << endl;
        cout << "Total Marks: " << S[i].total << endl;
        cout << "Average Marks: " << S[i].avg << endl;
        cout << "Average Grade: " << S[i].grade << endl;
    }

    return 0;
}