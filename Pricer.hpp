
#ifndef _PRICER_HPP
#define _PRICER_HPP
#include <vector>
#include <math.h>
#include <cmath>
#include "Crr.h"
#include "MonteCarlo.hpp"
#include "EuropeanOption.hpp"
#include "DigitalOption.hpp"
#include "Option.hpp"


using namespace std;

class Pricer {

private :

    double nDeep;
    const Option &opt;
    int fact(int n);

public:
    Pricer(const Option& op, double n );
    vector<double> CrrMethod();

};






#endif // _PRICER_HPP
