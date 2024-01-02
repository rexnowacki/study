
#include <iostream>
#include <string>

using namespace std;

class Invoice {
// Private data members of the class
private:
    string partNumber;
    string partDescription;
    int quantity;
    int pricePerItem;

public:
    Invoice(string partNum, string partDesc, int qty, int price) {
        partNumber = partNum;
        partDescription = partDesc;

        // Simple validation for quantity
        if (qty > 0) {
            quantity = qty;
        } else {
            quantity = 0;
        }

        // Simple validation for pricePerItem
        if (price > 0) {
            pricePerItem = price;
        } else {
            pricePerItem = 0;
        }
    }

    // Set and Get functions for partNumber
    void setPartNumber(string &partNum) {
        partNumber = partNum;
    }
    string getPartNumber() {
        return partNumber;
    }

    // Set and Get functions for partDescription
    void setPartDescription(string &partDesc) {
        partDescription = partDesc;
    }
    string getPartDescription() {
        return partDescription;
    }

    // Set and Get functions for quantity
    void setQuantity(int qty) {
        quantity = (qty > 0) ? qty : 0;
    }
    int getQuantity() {
        return quantity;
    }

    // Set and Get functions for pricePerItem
    void setPricePerItem(int price) {
        pricePerItem = (price > 0) ? price : 0;
    }
    int getPricePerItem() {
        return pricePerItem;
    }

    // Function to calculate and return the invoice amount
    int getInvoiceAmount() {
        return quantity * pricePerItem;
    }
};
