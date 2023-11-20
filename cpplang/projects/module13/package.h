#include <iostream>
#include <string>

using namespace std;

// Base class Package
class Package {
protected:
    string senderName, senderAddress, senderCity, senderState, senderZIP;
    string recipientName, recipientAddress, recipientCity, recipientState, recipientZIP;
    double weight; // in ounces
    double costPerOunce;

public:
    // Initialize member varibales
    Package(const string &sName, const string &sAddress, const string &sCity, 
            const string &sState, const string &sZIP, const string &rName, 
            const string &rAddress, const string &rCity, const string &rState, 
            const string &rZIP, double w, double cpo) 
    : senderName(sName), senderAddress(sAddress), senderCity(sCity), senderState(sState), senderZIP(sZIP),
      recipientName(rName), recipientAddress(rAddress), recipientCity(rCity), recipientState(rState), recipientZIP(rZIP),
      weight(w > 0 ? w : 0), costPerOunce(cpo > 0 ? cpo : 0) {}

    // Calculate cost of shipping
    virtual double calculateCost() const {
        return weight * costPerOunce;
    }
    // Getter methods for sender information
    string getSenderName() const { return senderName; }
    string getSenderAddress() const { return senderAddress; }
    string getSenderCity() const { return senderCity; }
    string getSenderState() const { return senderState; }
    string getSenderZIP() const { return senderZIP; }

    // Getter methods for recipient information
    string getRecipientName() const { return recipientName; }
    string getRecipientAddress() const { return recipientAddress; }
    string getRecipientCity() const { return recipientCity; }
    string getRecipientState() const { return recipientState; }
    string getRecipientZIP() const { return recipientZIP; }
    double getWeight() const { return weight; }
    double getCostPerOunce() const { return costPerOunce; }

};

