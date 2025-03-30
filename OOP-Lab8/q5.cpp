#include <iostream>
using namespace std;

class Item {
protected:
    string item_id;
    double item_price;

public:
    Item(string id, double cost) : item_id(id), item_price(cost) {}
    virtual double calculate_total_price() = 0;
    void set_price(double new_price) { item_price = new_price; }
    double get_price() const { return item_price; }
    string get_item_id() const { return item_id; }
};

class ElectronicsItem : public Item {
public:
    ElectronicsItem(string id, double cost) : Item(id, cost) {}
    double calculate_total_price() override {
        return item_price * 1.15;
    }
};

class ClothingItem : public Item {
public:
    ClothingItem(string id, double cost) : Item(id, cost) {}
    double calculate_total_price() override {
        return item_price * 1.05;
    }
};

class Cart {
private:
    Item** cart_items;
    int item_count;
    int max_capacity;

public:
    Cart(int max_items = 10) : item_count(0), max_capacity(max_items) {
        cart_items = new Item*[max_capacity];
    }
    ~Cart() {
        delete[] cart_items;
    }
    void add_item(Item* item) {
        if (item_count < max_capacity) {
            cart_items[item_count++] = item;
        }
    }
    void apply_percentage_discount(double percentage) {
        for (int i = 0; i < item_count; i++) {
            cart_items[i]->set_price(cart_items[i]->get_price() * (1 - percentage / 100));
        }
    }
    void apply_fixed_discount(double amount) {
        for (int i = 0; i < item_count; i++) {
            cart_items[i]->set_price(cart_items[i]->get_price() - amount);
        }
    }
    void buy_one_get_one_offer() {
        if (item_count < max_capacity && item_count > 0) {
            cart_items[item_count] = cart_items[item_count - 1];
            item_count++;
        }
    }
    Cart merge_with(const Cart &other) {
        Cart merged_cart(max_capacity + other.max_capacity);
        for (int i = 0; i < item_count; i++) {
            merged_cart.add_item(cart_items[i]);
        }
        for (int i = 0; i < other.item_count; i++) {
            merged_cart.add_item(other.cart_items[i]);
        }
        return merged_cart;
    }
    Cart remove_item(Item* item) {
        Cart updated_cart(max_capacity);
        for (int i = 0; i < item_count; i++) {
            if (cart_items[i]->get_item_id() != item->get_item_id()) {
                updated_cart.add_item(cart_items[i]);
            }
        }
        return updated_cart;
    }
    Cart apply_bulk_discount(double discount) {
        Cart discounted_cart = *this;
        discounted_cart.apply_percentage_discount(discount);
        return discounted_cart;
    }
    Cart split_bill(int users) {
        Cart split_cart = *this;
        for (int i = 0; i < split_cart.item_count; i++) {
            split_cart.cart_items[i]->set_price(split_cart.cart_items[i]->get_price() / users);
        }
        return split_cart;
    }
    void display_cart() {
        double total = 0;
        cout << "Cart:\n";
        for (int i = 0; i < item_count; i++) {
            cout << "Item: " << cart_items[i]->get_item_id() << " | Price: $" << cart_items[i]->calculate_total_price() << endl;
            total += cart_items[i]->calculate_total_price();
        }
        cout << "Total Amount: $" << total << "\n";
    }
};

int main() {
    ElectronicsItem laptop("E123", 1000);
    ClothingItem tshirt("C456", 50);

    Cart cart1;
    cart1.add_item(&laptop);
    cart1.add_item(&tshirt);
    cart1.display_cart();
    
    cart1.apply_percentage_discount(10);
    cout << "After 10% discount:\n";
    cart1.display_cart();
    
    Cart cart2;
    ElectronicsItem phone("E789", 800);
    cart2.add_item(&phone);
    
    Cart merged_cart = cart1.merge_with(cart2);
    cout << "After merging carts:\n";
    merged_cart.display_cart();
    
    Cart discounted_cart = merged_cart.apply_bulk_discount(5);
    cout << "After bulk discount:\n";
    discounted_cart.display_cart();
    
    Cart split_cart = merged_cart.split_bill(2);
    cout << "After splitting the total among 2 users:\n";
    split_cart.display_cart();
    
    return 0;
}
