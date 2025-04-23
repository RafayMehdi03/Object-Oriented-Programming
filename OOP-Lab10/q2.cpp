#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string name, email, summary;
    int years;
    cin >> name >> email >> years;
    cin.ignore();
    getline(cin, summary);
    ofstream resumeFile("resume.txt", ios::trunc);
    resumeFile << name << endl << email << endl << years << endl << summary << endl;
    resumeFile.close();

    string line;
    ifstream readResume("resume.txt");
    while (getline(readResume, line)) {
        cout << line << endl;
    }
    readResume.close();
    return 0;
}