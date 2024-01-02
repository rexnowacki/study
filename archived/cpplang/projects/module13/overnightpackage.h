#include <iostream>
#include <string>
// Derived class OvernightPackage
class OvernightPackage : public Package {
private:
    double additionalFeePerOunce;

public:
    OvernightPackage(const std::string &sName, const std::string &sAddress, const std::string &sCity, 
                     const std::string &sState, const std::string &sZIP, const std::string &rName, 
                     const std::string &rAddress, const std::string &rCity, const std::string &rState, 
                     const std::string &rZIP, double w, double cpo, double additionalFee)
    : Package(sName, sAddress, sCity, sState, sZIP, rName, rAddress, rCity, rState, rZIP, w, cpo), 
      additionalFeePerOunce(additionalFee) {}

    // Override calculateCost function to add addtional fee per ounce for overnight
    double calculateCost() const override {
        return Package::calculateCost() + weight * additionalFeePerOunce;
    }
};
