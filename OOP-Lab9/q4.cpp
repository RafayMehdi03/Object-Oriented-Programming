#include <iostream>
#include <string>

using namespace std;

class PaymentMethod {
public:
    virtual void processPayment(double amount) = 0;
    virtual ~PaymentMethod() {}
};

class CreditCard : public PaymentMethod {
private:
    string cardNumber;
public:
    CreditCard(string cn) {
        cardNumber = cn;
    }
    void processPayment(double amount) {
        cout << "Processing credit card payment of " << amount << " using card " << cardNumber << endl;
    }
};

class DigitalWallet : public PaymentMethod {
private:
    double balance;
public:
    DigitalWallet(double b) {
        balance = b;
    }
    void processPayment(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Payment of " << amount << " successful. Remaining balance: " << balance << endl;
        } else {
            cout << "Insufficient balance." << endl;
        }
    }
};

int main() {
    CreditCard cc("1111-2222-3333-4444");
    DigitalWallet dw(100);

    cc.processPayment(75);
    dw.processPayment(50);
    dw.processPayment(60);

    return 0;
}
