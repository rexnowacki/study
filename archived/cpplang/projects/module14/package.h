#ifndef PACKAGE_H
#define PACKAGE_H

#include <iostream>
#include <string>

using namespace std;

class Package {
protected:
    string senderName, senderAddress, senderCity, senderState, senderZIP;
    string recipientName, recipientAddress, recipientCity, recipientState, recipientZIP;
    double weight; // in ounces
    double costPerOunce;

public:
    Package(const string &sName, const string &sAddress, const string &sCity, 
            const string &sState, const string &sZIP, const string &rName, 
            const string &rAddress, const string &rCity, const string &rState, 
            const string &rZIP, double w, double cpo) 
        : senderName(sName), senderAddress(sAddress), senderCity(sCity), 
          senderState(sState), senderZIP(sZIP), recipientName(rName), 
          recipientAddress(rAddress), recipientCity(rCity), recipientState(rState), 
          recipientZIP(rZIP), weight(w), costPerOunce(cpo) {}

    virtual double calculateCost() const {
        return weight * costPerOunce;
    }

    // Getter methods for address details
    string getSenderName() const { return senderName; }
    string getSenderAddress() const { return senderAddress; }
    string getSenderCity() const { return senderCity; }
    string getSenderState() const { return senderState; }
    string getSenderZip() const { return senderZIP; }
    string getRecipientName() const { return recipientName; }
    string getRecipientAddress() const { return recipientAddress; }
    string getRecipientCity() const { return recipientCity; }
    string getRecipientState() const { return recipientState; }
    string getRecipientZip() const { return recipientZIP; }
};

#endif // PACKAGE_H
