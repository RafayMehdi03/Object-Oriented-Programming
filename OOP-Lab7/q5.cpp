#include <iostream>
#include <string>
using namespace std;

class Media {
protected:
    string title;
    string publicationDate;
    string uniqueID;
    string publisher;

public:
    Media(string t, string pubDate, string id, string pub)
        : title(t), publicationDate(pubDate), uniqueID(id), publisher(pub) {}

    virtual void displayInfo() {
        cout << "Title: " << title << ", Published: " << publicationDate << ", ID: " << uniqueID << endl;
    }

    virtual void checkOut() {
        cout << "Checking out " << title << endl;
    }

    virtual void returnItem() {
        cout << "Returning " << title << endl;
    }
};

class Book : public Media {
private:
    string author;
    string ISBN;

public:
    Book(string t, string pubDate, string id, string pub, string auth, string isbn)
        : Media(t, pubDate, id, pub), author(auth), ISBN(isbn) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Author: " << author << ", ISBN: " << ISBN << endl;
    }
};

int main() {
    Media* media = new Book("The Great Gatsby", "1925", "B001", "Scribner", "F. Scott Fitzgerald", "9780743273565");
    media->displayInfo();
    media->checkOut();
    media->returnItem();

    delete media;
    return 0;
}
