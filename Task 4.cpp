#include <iostream>
#include <string>
#include <vector>

class Item {
    // ... (same as before)
};

class Inventory {
private:
    std::vector<Item*> items; // Using std::vector to hold the items
    float total_money;

    static void display_data(const Item &item) {
        // ... (same as before)
    }

public:
    Inventory() : total_money{0} {}

    void add_item() {
        // ... (same as before)
        items.push_back(new Item(name, quantity, price)); // Adding new item to the vector
    }

    void sell_item() {
        // ... (same as before)
        if (input_quantity <= quantity) {
            // ... (same as before)
            if (quantity == 0) {
                // If the quantity becomes zero, remove the item from the vector
                delete item;
                items.erase(items.begin() + item_index);
            }
        } else {
            // ... (same as before)
        }
    }

    void list_items() {
        // ... (same as before)
    }
};

// ... (same as before)
