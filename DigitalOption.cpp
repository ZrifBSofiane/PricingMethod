#include "DigitalOption.hpp"




double DigitalOption::PayOff(double z, double k, bool isCall) const
{
    return isCall ?( (k-z) < 0 ? 1 : 0 ) : ( (k-z) > 0 ? 1 : 0 );
}

