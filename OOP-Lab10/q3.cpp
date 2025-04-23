#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string line;
    ifstream chapter1("chapter1.txt");
    ifstream chapter2("chapter2.txt");
    ofstream book("book.txt", ios::app);
    while (getline(chapter1, line)) {
        book << line << endl;
    }
    book << endl;
    while (getline(chapter2, line)) {
        book << line << endl;
    }
    chapter1.close();
    chapter2.close();
    book.close();

    ifstream bookRead("book.txt");
    while (getline(bookRead, line)) {
        cout << line << endl;
    }
    bookRead.close();
    return 0;
}