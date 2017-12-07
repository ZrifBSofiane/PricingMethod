#ifndef _MONTE_CARLO_HPP
#define _MONTE_CARLO_HPP

#include <math.h>
#include <iostream>
#include <random>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>
#include <vector>
#include <boost/math/distributions.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/variate_generator.hpp>
#include <boost/random/normal_distribution.hpp>


#include "EuropeanOption.hpp"

using namespace std;

class MonteCarlo{

private:
    double r, sigma, k, S, T;
    int nSimu;
    vector<double> value;
    double sumVector(vector<double> vect);
  //  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator;
    bool way; // true call
    const Option &opt;


public :
    MonteCarlo(const Option& op, double n);
    MonteCarlo(const Option& op,double r, double si, double k, double s, double t, double n, bool way);
    double call_payOff(double ST,double K);
    double put_payOff(double ST,double K);
    double computeAsset();
    double simulate();

};















#endif // _MONTE_CARLO_HPP
