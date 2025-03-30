#include <iostream>
using namespace std;

class Account {
private:
    string accNumber;
    double accBalance;

public:
    Account(string accNumber, double accBalance) : accNumber(accNumber), accBalance(accBalance) {}
    virtual void computeInterest() = 0;

    void setAccNumber(string accNumber) {
        this->accNumber = accNumber;
    }

    string getAccNumber() const {
        return accNumber;
    }

    void setAccBalance(double accBalance) {
        this->accBalance = accBalance;
    }

    double getAccBalance() const {
        return accBalance;
    }

    void depositAmount(double amount) {
        accBalance += amount;
        cout << "Cash deposit of Rs." << amount << " successful! Your new balance is: Rs." << accBalance << endl;
    }

    void depositWithCheck(double amount, string checkId) {
        accBalance += amount;
        cout << "Check deposit of Rs." << amount << " (Check No: " << checkId << ") successful! Your new balance is: Rs." << accBalance << endl;
    }

    void depositOnlineTransfer(double amount) {
        accBalance += amount;
        cout << "Online transfer of Rs." << amount << " successful! Your new balance is: Rs." << accBalance << endl;
    }

    virtual void withdrawAmount(double amount) = 0;
    virtual void showDetails() = 0;
};

class Savings : public Account {
public:
    Savings(string accNumber, double accBalance) : Account(accNumber, accBalance) {}

    void computeInterest() override {
        setAccBalance(getAccBalance() * 1.05);
        cout << "Annual interest applied! New balance: Rs." << getAccBalance() << endl;
    }

    void withdrawAmount(double amount) override {
        if (getAccBalance() - amount < 500) {
            cout << "Oops! You need to maintain at least Rs.500 in your savings account." << endl;
        } else {
            setAccBalance(getAccBalance() - amount);
            cout << "Withdrawal of Rs." << amount << " successful! Remaining balance: Rs." << getAccBalance() << endl;
        }
    }

    void showDetails() override {
        cout << "Savings Account - Account Number: " << getAccNumber() << " | Balance: Rs." << getAccBalance() << endl;
    }

    Savings operator+(const Savings &other) {
        return Savings("Merged", this->getAccBalance() + other.getAccBalance());
    }

    Savings operator-(double amount) {
        return Savings(this->getAccNumber(), this->getAccBalance() - amount);
    }

    Savings operator*(double interestRate) {
        return Savings(this->getAccNumber(), this->getAccBalance() * (1 + interestRate));
    }

    Savings operator/(int installments) {
        return Savings(this->getAccNumber(), this->getAccBalance() / installments);
    }
};

class Current : public Account {
public:
    Current(string accNumber, double accBalance) : Account(accNumber, accBalance) {}

    void computeInterest() override {}

    void withdrawAmount(double amount) override {
        if (getAccBalance() - amount < -1000) {
            cout << "Sorry! Overdraft limit of Rs.1000 exceeded. Transaction declined." << endl;
        } else {
            setAccBalance(getAccBalance() - amount);
            cout << "Withdrawal of Rs." << amount << " successful! Remaining balance: Rs." << getAccBalance() << endl;
        }
    }

    void showDetails() override {
        cout << "Current Account - Account Number: " << getAccNumber() << " | Balance: Rs." << getAccBalance() << endl;
    }
};

int main() {
    Savings savings("S123", 1000);
    Current current("C456", 500);

    savings.depositAmount(200);
    savings.depositWithCheck(300, "BAHBL0948338");
    savings.depositOnlineTransfer(500);

    savings.withdrawAmount(400);
    savings.withdrawAmount(800);

    current.depositAmount(1000);
    current.withdrawAmount(1200);
    current.withdrawAmount(500);

    Savings savings2("S789", 2000);
    Savings merged = savings + savings2;
    merged.showDetails();

    Savings deducted = savings - 200;
    deducted.showDetails();

    Savings interestApplied = savings * 0.05;
    interestApplied.showDetails();

    Savings installmentPayment = savings / 5;
    installmentPayment.showDetails();

    return 0;
}
