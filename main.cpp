#include <iostream>
#include <math.h>


#include "EuropeanOption.hpp"
#include "DigitalOption.hpp"
#include "MonteCarlo.hpp"
#include "tree.h"
#include "Crr.h"
#include "string.h"
#include "AmericanOption.hpp"

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



    cout << "Choose r : ";
    cin >> r ;

    cout << "Choose k : " ;
    cin >> k ;

    cout << "Choose s : " ;
    cin >> s ;

    cout << "Choose t : " ;
    cin >> k ;

    cout << "Choose sigma : " ;
    cin >> sigma ;

    cout << "Call: 1 // Put: 2  ?" ;
    int valueCallPut = 0;
    cin >> valueCallPut;
    way = valueCallPut == 1 ? true : false ;


    double up = exp( (r+sigma*sigma/2)*k +sigma*sqrt(k)) -1;
    double down = exp( (r+sigma*sigma/2)*k -sigma*sqrt(k)) -1;


    EuropeanOption euro(r,k,s,t,way,sigma);
    AmericanOption ameri(r,k,s,t,way,sigma);
    DigitalOption digi(r,k,s,t,way,sigma);

    EuropeanOption euroCrr(r,k,s,t,way,up, down);
    AmericanOption AmeriCrr(r,k,s,t,way,up, down);
    DigitalOption digiCrr(r,k,s,t,way,up, down);

    cout << "Choose an option " << endl;
    cout << "American(1) -- European(2) -- Digital(3) : " ;
    int optionChoice = 0;
    cin >> optionChoice ;
    if(optionChoice == 1)
    {
        BS black(ameri);       // Black and Schole
        MonteCarlo test(ameri,100);  // Monte Carlo
        Pricer price(AmeriCrr,0);    // Crr
        vector<double> resultCrr = price.CrrMethod();

        cout << "BS Put : " <<  black.computePut(0) << endl;
        cout << "BS Call : " <<  black.computeCall(0) << endl;
        cout << "MonteCarlo " << test.simulate() << endl;
        cout << "Iteration formula CRR : " << resultCrr[0] << endl;
        cout << "Closed formula CRR : " << resultCrr[1] << endl;
    }
    if(optionChoice == 3)
    {
        BS black(digi);       // Black and Schole
        MonteCarlo test(digi,100);  // Monte Carlo
        Pricer price(digiCrr,0);    // Crr
        vector<double> resultCrr = price.CrrMethod();

        cout << "BS Put : " <<  black.computePut(0) << endl;
        cout << "BS Call : " <<  black.computeCall(0) << endl;
        cout << "MonteCarlo " << test.simulate() << endl;
        cout << "Iteration formula CRR : " << resultCrr[0] << endl;
        cout << "Closed formula CRR : " << resultCrr[1] << endl;
    }
    if(optionChoice != 1 && optionChoice != 3)
    {
        BS black(euro);       // Black and Schole
        MonteCarlo test(euro,100);  // Monte Carlo
        Pricer price(euroCrr,0);    // Crr
        vector<double> resultCrr = price.CrrMethod();

        cout << "BS Put : " <<  black.computePut(0) << endl;
        cout << "BS Call : " <<  black.computeCall(0) << endl;
        cout << "MonteCarlo " << test.simulate() << endl;
        cout << "Iteration formula CRR : " << resultCrr[0] << endl;
        cout << "Closed formula CRR : " << resultCrr[1] << endl;

    }





    return 0;
}
