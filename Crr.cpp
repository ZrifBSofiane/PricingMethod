#include "Crr.h"


Crr::Crr()
{
    this->h=0;
}


void Crr::SetS(double s)
{
    this->s = s;
}
double Crr::GetS()
{
    return this->s;
}

void Crr::SetH(double h)
{
    this->h = h;
}
double Crr::GetH()
{
    return this->h;
}
double Crr::ComputeH(double S0,double value, bool way)
{
    if(way)
        return std::max((double)0,value-S0);
    else
        return std::max((double)0,S0-value);
}

double Crr::ComputeS(double s0,double up, double down, int n, int i)
{
    return s0*(pow((1+up),i))*(pow(1+down,n-i));
}
