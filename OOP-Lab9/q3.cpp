#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;
    string ISBN;
public:
    Book(string t, string a, string i) {
        title = t;
        author = a;
        ISBN = i;
    }
    string getTitle() {
        return title;
    }
    string getAuthor() {
        return author;
    }
    string getISBN() {
        return ISBN;
    }
};

int main() {
    Book b("1984", "George Orwell", "1234567890");

    cout << "Title: " << b.getTitle() << endl;
    cout << "Author: " << b.getAuthor() << endl;
    cout << "ISBN: " << b.getISBN() << endl;

    return 0;
}
