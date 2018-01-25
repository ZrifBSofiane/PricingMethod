
#ifndef _AMERICANOPTION_HPP
#define _AMERICANOPTION_HPP
#include <iostream>
#include "Option.hpp"
#include <string>


using namespace std;

class AmericanOption : public Option  {


public :
    using Option::Option;
    explicit AmericanOption(double r, double k, double s, double t, bool way, double sigma) : Option(r,k,s,t,way,sigma) {};
    explicit AmericanOption(double r, double k, double s, double t, bool way, double up, double down): Option( r,k,s,t,way,up,down) {}; // Only CRR



    virtual double PayOff(double z, double k, bool isCall) const;
    virtual string getClasseName() const;



};




#endif // _EUROPEANOPTION_HPP
