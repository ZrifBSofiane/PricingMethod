#ifndef _BS_HPP
#define _BS_HPP
#include "Option.hpp"

#include <math.h>
#include <iostream>
#include <boost/math/distributions.hpp>

class BS {

private:
    double r, sigma, k, S, b, T;
    const Option &opt;

public:
   // BS();
    BS(const Option& op);
   // BS(double r, double sigma, double k, double s,double T);
    double computeD1(double t);
    double computeD2(double t);
    double computeCall(double t);
    double computePut(double t);


};



#endif // _BS_HPP
