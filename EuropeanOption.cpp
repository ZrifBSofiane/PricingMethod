#include "EuropeanOption.hpp"




double EuropeanOption::PayOff(double z, double k, bool isCall) const
{
    return isCall ? max(0.0,z-k) : max (0.0,k-z);
}

string EuropeanOption::getClasseName() const
{
    return "EuropeanOption";
}
