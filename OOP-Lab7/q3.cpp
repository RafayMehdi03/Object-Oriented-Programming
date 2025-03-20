#include <iostream>
#include <string>
using namespace std;

class Currency {
protected:
    double amount;
    string currencyCode;
    string currencySymbol;

public:
    Currency(double amt, string code, string symbol)
        : amount(amt), currencyCode(code), currencySymbol(symbol) {}

    virtual void convertToBase() = 0;
    virtual void convertTo(Currency* targetCurrency) = 0;

    void displayCurrency() {
        cout << "Amount: " << amount << " " << currencySymbol << " (" << currencyCode << ")" << endl;
    }
};

class Dollar : public Currency {
public:
    Dollar(double amt) : Currency(amt, "USD", "$") {}

    void convertToBase() override {
        cout << "Converting " << amount << " " << currencySymbol << " to base currency..." << endl;
    }

    void convertTo(Currency* targetCurrency) override {
        cout << "Converting " << amount << " " << currencySymbol << " to target currency." << endl;
    }
};

int main() {
    Currency* currency = new Dollar(100);
    currency->displayCurrency();
    currency->convertToBase();
    
    delete currency;
    return 0;
}
