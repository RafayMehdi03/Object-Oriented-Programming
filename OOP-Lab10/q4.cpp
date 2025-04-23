#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream info("info.txt", ios::out);
    info << "C++ is a powerful programming language.";
    info.close();

    fstream file("info.txt", ios::in | ios::out);
    cout << file.tellg() << endl;
    cout << file.tellp() << endl;
    file.seekg(6);
    string word;
    file >> word;
    cout << word << endl;
    file.seekp(6);
    file << "dynamic";
    cout << file.tellg() << endl;
    cout << file.tellp() << endl;
    file.seekg(0);
    string content;
    getline(file, content);
    cout << content << endl;
    file.close();
    return 0;
}