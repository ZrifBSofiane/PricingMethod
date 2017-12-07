#include "Option.hpp"

Option::Option()
{

}
Option::Option(const Option& op)
{
    this->s = op.s;
    this->up = op.up;
    this->down = op.down;
    this->r = op.r;
    this->k = op.k;
    this->sigma = op.sigma;
    this->t = op.t;
    this->way = op.way;
}


Option::Option(double r, double k, double s, double t, bool way, double sigma)
{
    this->s = s;
    this->r = r;
    this->k = k;
    this->way = way;
    this->t = t;
    this->sigma = sigma;


}


Option::Option(double r, double k, double s, double t, bool way, double up, double down)
{
    this->s = s;
    this->r = r;
    this->k = k;
    this->up = up;
    this->down = down;
    this->t = t;
    this->way;
}

double Option::GetS() const
{
    return this->s;
}
double Option::GetUp() const
{
    return this->up;
}
double Option::GetDown() const
{
    return this->down;
}
double Option::GetR() const
{
    return this->r;
}
double Option::GetK() const
{
    return this->k;
}
double Option::GetSigma() const
{
    return this->sigma;
}
double Option::GetT() const
{
    return this->t;
}

bool Option::GetWay() const
{
    return this->way;
}



