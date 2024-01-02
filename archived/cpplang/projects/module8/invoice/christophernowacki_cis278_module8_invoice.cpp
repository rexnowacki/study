#include "invoice.h"
#include <iostream>
#include <string>

using namespace std;

// Test program
int main() {
    // Creating an invoice object
    Invoice invoice1("001", "Hammer", 5, 10); // ID, Name, Quantity, Price
    Invoice invoice2("002", "Table Saw", 1, 100);
    
    // Displaying details of the invoice
    cout << "Part Number: " << invoice1.getPartNumber() << endl;
    cout << "Part Description: " << invoice1.getPartDescription() << endl;
    cout << "Quantity: " << invoice1.getQuantity() << endl;
    cout << "Price per Item: $" << invoice1.getPricePerItem() << endl;
    cout << "Total Invoice Amount: $" << invoice1.getInvoiceAmount() << endl;
    
    cout << endl << endl;
    cout << "Setting Quantity and Price to invalid values...";
    // Demonstrating the functionality to set invalid values
    invoice1.setQuantity(-5);
    invoice1.setPricePerItem(-10);
    cout << endl << endl;

    // Displaying Updated values
    cout << "\nAfter setting invalid values:" << endl;
    cout << "Quantity: " << invoice1.getQuantity() << endl;  // Should be 0
    cout << "Price per Item: $" << invoice1.getPricePerItem() << endl;  // Should be 0
    cout << "Total Invoice Amount: $" << invoice1.getInvoiceAmount() << endl;  // Should be 0

    return 0;
}
