#include <iostream>
#include <math.h>


#include "EuropeanOption.hpp"
#include "DigitalOption.hpp"
#include "MonteCarlo.hpp"
#include "tree.h"
#include "Crr.h"
#include "string.h"

#include "BinLattice.hpp"

#include "BS.hpp"

#include <boost/math/distributions.hpp>
#include "Pricer.hpp"


using namespace std;






int main()
{

    double r = 0.02;
    double k = 95;
    double s =100;
    double t = 3;
    bool way = true;
    double sigma = 0.15;

    double up = 0.03;
    double down = -0.03;




    cout << "up " << up << endl;


    EuropeanOption euro(r,k,s,t,way,sigma);
    //DigitalOption euro(0.02,95,100,1,false,0.15);
    EuropeanOption euroCrr(r,k,s,t,way,up, down);


    BS black(euro);       // Black and Schole
    MonteCarlo test(euro,100);  // Monte Carlo
    Pricer price(euroCrr,0);    // Crr
    vector<double> resultCrr = price.CrrMethod();

    cout << "BS Put : " <<  black.computePut(0) << endl;
    cout << "BS Call : " <<  black.computeCall(0) << endl;
    cout << "MonteCarlo " << test.simulate() << endl;
    cout << "Iteration formula CRR : " << resultCrr[0] << endl;
    cout << "Closed formula CRR : " << resultCrr[1] << endl;












    return 0;
}
