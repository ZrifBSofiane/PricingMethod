#ifndef _DIGITALOPTION_HPP
#define _DIGITALOPTION_HPP
#include <iostream>
#include "Option.hpp"


using namespace std;

class DigitalOption : public Option  {


public :
    using Option::Option;
     explicit DigitalOption(double r, double k, double s, double t, bool way, double sigma) : Option(r,k,s,t,way,sigma) {};
     explicit DigitalOption(double r, double k, double s, double t, bool way, double up, double down): Option( r,k,s,t,way,up,down) {}; // Only CRR



    virtual double PayOff(double z, double k, bool isCall) const;

};




#endif // _EUROPEANOPTION_HPP
