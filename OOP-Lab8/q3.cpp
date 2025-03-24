//q1
#include <iostream>
using namespace std;
class Bank_Account {
private:
    double balance;
public:
    Bank_Account(double bal) : balance(bal) {}

    // Overloading += as a member function
    Bank_Account& operator+=(double amount) {
        balance += amount;
        return *this;
    }
};





//q2
#include <iostream>
using namespace std;
class Bank_Account {
private:
    double balance;
public:
    Bank_Account(double bal) : balance(bal) {}

    // Friend function to allow object + primitive type
    friend Bank_Account operator+(const Bank_Account &acc, double amount) {
        return Bank_Account(acc.balance + amount);
    }
    
    void display() const {
        cout << "Balance: $" << balance << endl;
    }
};

int main() {
    Bank_Account acc(1000);
    Bank_Account new_acc = acc + 500; // Adding 500 to account balance
    new_acc.display(); // Output: Balance: $1500
}




//q3
#include <iostream>
using namespace std;
class Bank_Account {
private:
    double balance;
public:
    Bank_Account(double bal) : balance(bal) {}

    // Friend function declaration
    friend void show_balance(const Bank_Account &acc);
};

// Friend function accessing private members
void show_balance(const Bank_Account &acc) {
    cout << "Balance: $" << acc.balance << endl; // Accessing private member
}

int main() {
    Bank_Account acc(2000);
    show_balance(acc); // Output: Balance: $2000
}