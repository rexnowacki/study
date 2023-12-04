// Christopher Nowacki
// CIS 278
// Module 14 -- Package Shipping Update
#include <iostream>
#include <vector>
#include <memory>
#include "twodaypackage.h"
#include "overnightpackage.h"
#include <iomanip>

using namespace std;

int main() {
    vector<shared_ptr<Package>> packages;

    // Add packages to the vector
    packages.push_back(make_shared<TwoDayPackage>("Elizabeth Zott", "4900 Hastings St.", "Birmingham", "Alabama", "35005", 
                                                  "Jeff Daniels", "339 Buffalo Circle", "Atlanta", "Georgia", "30305", 
                                                  20, 0.50, 2.00)); // weight, costPerOunce, flatFee
    packages.push_back(make_shared<OvernightPackage>("Ryan Gosling", "449 Franklin Ave.", "Ventura", "California", "93001", 
                                                     "Nicolas Cage", "5109 Mars Dr.", "Albuquerque", "New Mexico", "87123", 
                                                     5, 0.70, 1.00)); // weight, costPerOunce, overnightFee

    double totalCost = 0.0;
// Iterate through packages vector
    for (const auto& pkg : packages) {
        // Display addresses
        cout << "Sender: " << pkg->getSenderName() << "\n" << pkg->getSenderAddress() << ", " 
             << pkg->getSenderCity() << ", " << pkg->getSenderState() << " " << pkg->getSenderZip() << "\n";
        cout << "Recipient: " << pkg->getRecipientName() << "\n" << pkg->getRecipientAddress() << ", " 
             << pkg->getRecipientCity() << ", " << pkg->getRecipientState() << " " << pkg->getRecipientZip() << "\n";

        // Calculate and display cost
        double cost = pkg->calculateCost();
        cout << fixed << setprecision(2); 
        cout << "Shipping Cost: $" << cost << "\n\n";
        totalCost += cost;
    }

    cout << "Total Shipping Cost: $" << fixed << setprecision(2) << totalCost << endl;

    return 0;
}
