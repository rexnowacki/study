#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

#include "package.h"

class OvernightPackage : public Package {
private:
    double additionalFeePerOunce;

public:
    OvernightPackage(const string &senderName, const string &senderAddress, const string &senderCity, 
                     const string &senderState, const string &senderZIP, const string &receiverName, 
                     const string &receiverAddress, const string &receiverCity, const string &receiverState, 
                     const string &receiverZIP, double weight, double costPerOunce, double afpo) 
        : Package(senderName, senderAddress, senderCity, senderState, senderZIP, receiverName, receiverAddress, receiverCity, receiverState, receiverZIP, weight, costPerOunce), additionalFeePerOunce(afpo) {}

    double calculateCost() const override {
        return Package::calculateCost() + weight * additionalFeePerOunce;
    }
};
#endif // OVERNIGHTPACKAGE_H
