#include "BS.hpp"








BS::BS(const Option& op) : opt(op)
{
    this->r = opt.GetR();
    this->sigma = opt.GetSigma();
    this->k = opt.GetK();
    this->S = opt.GetS();
    this->T = opt.GetT();
}




double BS::computeD1(double t)
{
    double res = (log(this->S / this->k) + (this->r + 0.5 * pow(this->sigma,2))*(this->T - t) );
    res = res / (this->sigma*sqrt(this->T - t));
    return res;
}

double BS::computeD2(double t)
{
    double res = this->computeD1(t) - (this->sigma*sqrt(this->T - t));
    return res;
}

double BS::computeCall(double t)
{
    boost::math::normal_distribution<> N(0,1);

    double d1 = this->computeD1(t);
    double d2 = this->computeD2(t);

    double normalLawCumulFunctionD1 = cdf(N,d1);
    double normalLawCumulFunctionD2 = cdf(N,d2);

    double res = this->S*normalLawCumulFunctionD1 - this->k*exp(-1*this->r*(this->T-t))*normalLawCumulFunctionD2;
    return res;
}

double BS::computePut(double t)
{
    boost::math::normal_distribution<> N(0,1);

    double d1 = this->computeD1(t);
    double d2 = this->computeD2(t);

    double normalLawCumulFunctionD1 = cdf(N,-1*d1);
    double normalLawCumulFunctionD2 = cdf(N,-1*d2);

    double res = this->k * exp(-1*this->r*(this->T-t)) * normalLawCumulFunctionD2 - this->S*normalLawCumulFunctionD1;
    return res;
}
