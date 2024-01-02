// Christopher Nowacki
// CIS 278
// Package Inheritance Program

#include <iostream>
#include <string>
#include "package.h"
#include "twodaypackage.h"
#include "overnightpackage.h"

// Main 
int main() {
    TwoDayPackage package1("Ryan Gosling", "5151 Forest St", "Bozeman", "MT", "59715", "Nick Cage", "1476 Elm St", "Atlanta", "GA", "30033", 40, 0.65, 2.0);
    // 40 oz package, .65 cents per oz, $2.00 flat fee for two day
    OvernightPackage package2("Charlie Day", "788 Tucson Blvd", "Tucson", "AZ", "85711", "Mia Goth", "666 Westwood Ct", "Albuquerque", "NM", "87109", 5, 0.65, 0.3);
    // 5 oz package, .65 cents per oz, $0.30 aditional fee per ounce
    cout << "Two Day Package:\n";
    cout << "Sender: " << package1.getSenderName() << ", " << package1.getSenderAddress() << ", " << package1.getSenderCity() << ", " << package1.getSenderState() << ", " << package1.getSenderZIP() << "\n";
    cout << "Recipient: " << package1.getRecipientName() << ", " << package1.getRecipientAddress() << ", " << package1.getRecipientCity() << ", " << package1.getRecipientState() << ", " << package1.getRecipientZIP() << "\n";
    cout << "Total Ounces: " << package1.getWeight() << "\n";
    cout << "Cost per Ounce: $" << package1.getCostPerOunce() << "\n";
    cout << "Cost: $" << package1.calculateCost() << "\n\n";

    cout << "Overnight Package:\n";
    cout << "Sender: " << package2.getSenderName() << ", " << package2.getSenderAddress() << ", " << package2.getSenderCity() << ", " << package2.getSenderState() << ", " << package2.getSenderZIP() << "\n";
    cout << "Recipient: " << package2.getRecipientName() << ", " << package2.getRecipientAddress() << ", " << package2.getRecipientCity() << ", " << package2.getRecipientState() << ", " << package2.getRecipientZIP() << "\n";
    cout << "Total Ounces: " << package2.getWeight() << "\n";
    cout << "Cost per Ounce: $" << package2.getCostPerOunce() << "\n";
    cout << "Cost: $" << package2.calculateCost() << "\n";

    return 0;
}
