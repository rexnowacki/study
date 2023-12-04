#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include "package.h"

class TwoDayPackage : public Package {
private:
    double flatFee;

public:
    TwoDayPackage(const string &sName, const string &sAddress, const string &sCity, 
                  const string &sState, const string &sZIP, const string &rName, 
                  const string &rAddress, const string &rCity, const string &rState, 
                  const string &rZIP, double w, double cpo, double ff) 
        : Package(sName, sAddress, sCity, sState, sZIP, rName, rAddress, rCity, rState, rZIP, w, cpo), flatFee(ff) {}

    double calculateCost() const override {
        return Package::calculateCost() + flatFee;
    }
};

#endif // TWODAYPACKAGE_H
