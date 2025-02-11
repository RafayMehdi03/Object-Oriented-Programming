#include <iostream>
#include <string>
using namespace std;

struct Product {
    int id;
    string name;
    float price;
    int quantity;
};
Product products[100];
int productCount = 0;
void addProduct() {
    int id;
    string name;
    float price;
    int quantity ;
    cout << "Enter product ID: ";
    cin >> products[productCount].id;
    cout << "Enter product name: ";
    cin >> products[productCount].name;
    cout << "Enter product price: ";
    cin >> products[productCount].price;
    cout << "Enter product quantity: ";
    cin >> products[productCount].quantity;
    productCount++;
}

void displayProduct(int id) {
    if (id > 0 && id <= productCount) {
        cout << "ID: " << products[id - 1].id << endl;
        cout << "Name: " << products[id - 1].name << endl;
        cout << "Price: " << products[id - 1].price << endl;
        cout << "Quantity: " << products[id - 1].quantity << endl;
    } else {
        cout << "Product not found!" << endl;
    }
}

void updateProduct(int id) {
    if (id > 0 && id <= productCount) {
        float price;
        int quantity;
        cout << "Enter new price: ";
        cin >> price;
        cout << "Enter new quantity: ";
        cin >> quantity;
        products[id - 1].price = price;
        products[id - 1].quantity = quantity;
    } else {
        cout << "Product not found!" << endl;
    }
}

void removeProduct(int id) {
    if (id > 0 && id <= productCount) {
        for (int i = id - 1; i < productCount - 1; i++) {
            products[i] = products[i + 1];
        }
        productCount--;
        cout << "Product Removed" << endl ;
    } else {
        cout << "Product not found!" << endl;
    }
}

int main() {
    int choice, id;
    while (true) {
        cout << "1. Add Product\n2. Display Product\n3. Update Product\n4. Remove Product\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                cout << "Enter product ID to display: ";
                cin >> id;
                displayProduct(id);
                break;
            case 3:
                cout << "Enter product ID to update: ";
                cin >> id;
                updateProduct(id);
                break;
            case 4:
                cout << "Enter product ID to remove: ";
                cin >> id;
                removeProduct(id);
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}