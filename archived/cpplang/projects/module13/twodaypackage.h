#include <iostream>
#include <string>

// Derived class TwoDayPackage
class TwoDayPackage : public Package {
private:
    double flatFee; // Flat-fee for 2 day

public:
    TwoDayPackage(const std::string &sName, const std::string &sAddress, const std::string &sCity, 
                  const std::string &sState, const std::string &sZIP, const std::string &rName, 
                  const std::string &rAddress, const std::string &rCity, const std::string &rState, 
                  const std::string &rZIP, double w, double cpo, double fee)
    : Package(sName, sAddress, sCity, sState, sZIP, rName, rAddress, rCity, rState, rZIP, w, cpo), flatFee(fee) {}

    // Overrides calculateCost function for flat fee inclusion
    double calculateCost() const override {
        return Package::calculateCost() + flatFee;
    }
};

