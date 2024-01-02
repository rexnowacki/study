// Program using a vector to list cheap items, etc.

#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    std::string name;
    double price;
};

int main() {
    std::vector<Item> shoppingList = {
        {"kelsey", 5.0},
        {"helena", 1000.0},
        {"daniela", 1000.0},
        {"rachel", 25.0}
    };

    std::vector<Item> cheapItems;

    // Copy items under 10 dollars to cheapItems
    std::copy_if(shoppingList.begin(), shoppingList.end(), std::back_inserter(cheapItems),
                 [](const Item& item) { return item.price > 100.0; });

    // Remove items under 10 dollars from shoppingList
    auto newEnd = std::remove_if(shoppingList.begin(), shoppingList.end(),
                                 [](const Item& item) { return item.price > 100.0; });

    shoppingList.erase(newEnd, shoppingList.end());

    // Print cheap items
    for (const auto& item : cheapItems) {
        std::cout << item.name << " - $" << item.price << std::endl;
    }

    return 0;
}
