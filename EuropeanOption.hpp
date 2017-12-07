#ifndef _EUROPEANOPTION_HPP
#define _EUROPEANOPTION_HPP
#include <iostream>
#include "Option.hpp"


using namespace std;

class EuropeanOption : public Option  {


public :
    using Option::Option;
    explicit EuropeanOption(double r, double k, double s, double t, bool way, double sigma) : Option(r,k,s,t,way,sigma) {};
    explicit EuropeanOption(double r, double k, double s, double t, bool way, double up, double down): Option( r,k,s,t,way,up,down) {}; // Only CRR



    virtual double PayOff(double z, double k, bool isCall) const;



};




#endif // _EUROPEANOPTION_HPP
