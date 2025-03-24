#include <iostream>
using namespace std;

class Bank_Account {
private:
    string acc_number;
    string acc_holder;
    double acc_balance;

public:
    Bank_Account(string number, string holder, double balance)
        : acc_number(number), acc_holder(holder), acc_balance(balance) {}

    Bank_Account operator+(const Bank_Account &other) const {
        return Bank_Account(acc_number, acc_holder, acc_balance + other.acc_balance);
    }

    Bank_Account &operator-=(double amount) {
        if (amount <= acc_balance) {
            acc_balance -= amount;
        } else {
            cout << "Insufficient balance!\n";
        }
        return *this;
    }

    bool operator>(const Bank_Account &other) const {
        return acc_balance > other.acc_balance;
    }

    string get_acc_holder() const { return acc_holder; }
    double get_acc_balance() const { return acc_balance; }

    friend ostream &operator<<(ostream &out, const Bank_Account &acc) {
        out << "Account: " << acc.acc_holder << ", Balance: $" << acc.acc_balance;
        return out;
    }
};

int main() {
    Bank_Account acc_1("001", "Shafique Rehman", 5000);
    Bank_Account acc_2("002", "Talha", 3000);

    cout << acc_1 << endl;
    cout << acc_2 << endl;

    Bank_Account total_balance = acc_1 + acc_2;
    cout << "\nAfter Addition:\n" << total_balance << endl;

    acc_1 -= 2000;
    acc_2 = Bank_Account("002", acc_2.get_acc_holder(), acc_2.get_acc_balance() + 2000);

    cout << "\nAfter Transfer:\n";
    cout << acc_1 << endl;
    cout << acc_2 << endl;

    cout << "\nComparison:\n";
    if (acc_1 > acc_2) {
        cout << acc_1.get_acc_holder() << " has more balance.\n";
    } else {
        cout << acc_2.get_acc_holder() << " has more balance.\n";
    }

    return 0;
}
