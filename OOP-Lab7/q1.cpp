#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    string accountNumber;
    double balance;
    string accountHolderName;
    string accountType;

public:
    Account(string accNum, double bal, string holderName, string type = "Standard")
        : accountNumber(accNum), balance(bal), accountHolderName(holderName), accountType(type) {}

    virtual void deposit(double amount) {
        balance += amount;
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }

    virtual void calculateInterest() {
        cout << "Interest calculation not available for this account type." << endl;
    }

    void printStatement() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Holder Name: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
        cout << "Account Type: " << accountType << endl;
    }

    void getAccountInfo() {
        cout << "Account Info: " << accountHolderName << ", " << accountNumber << endl;
    }
};

class SavingsAccount : public Account {
protected:
    double interestRate;

public:
    SavingsAccount(string accNum, double bal, string holderName, double rate)
        : Account(accNum, bal, holderName, "Savings"), interestRate(rate) {}

    void calculateInterest() override {
        double interest = balance * interestRate / 100;
        cout << "Interest: " << interest << endl;
        balance += interest;
    }

    void printStatement() override {
        Account::printStatement();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

int main() {
    Account* acc = new SavingsAccount("SAV123", 1000, "John Doe", 5);
    acc->deposit(500);
    acc->withdraw(200);
    acc->calculateInterest();
    acc->printStatement();

    delete acc;
    return 0;
}
