#include <iostream>
#include <string>

using namespace std;

class Account {
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    Account() {
        balance = 0.0;
    }
    Account(string accNum, string holderName, double initialBalance) {
        accountNumber = accNum;
        accountHolderName = holderName;
        balance = initialBalance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }

    void checkBalance() {
        cout << "Current Balance: " << balance << endl;
    }
};

int main() {
    Account acc1("12345", "Alice", 1000.0);
    Account acc2("67890", "Bob",500.0);
    cout << "Account 1" << endl ;
    acc1.checkBalance();
    acc1.deposit(500.0);
    acc1.checkBalance();
    acc1.withdraw(200.0);
    acc1.checkBalance();
    acc1.withdraw(1500.0);
    cout << "Account 2" << endl ;
    acc2.checkBalance();
    acc2.deposit(800.0);
    acc2.checkBalance();

    return 0;
}