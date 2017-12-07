#ifndef _CRR_H
#define _CRR_H
#include <math.h>
#include <iostream>
#include <algorithm>

class Crr{

private :
    double s;
    double h;

public:
    Crr();
    void SetS(double s);
    double GetS();
    void SetH(double h);
    double GetH();
    double ComputeH(double S0,double value, bool way);
    double ComputeS(double s0,double up, double down, int n, int i);
};








#endif // _CRR_H
