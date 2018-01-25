#ifndef _OPTION_HPP
#define _OPTION_HPP
#include <string>

using namespace std;

class Option {

public:
    explicit Option();
    Option(const Option& op);
    explicit Option(double r, double k, double s, double t, bool way, double sigma);
    explicit Option(double r, double k, double s, double t, bool way, double up, double down);
    virtual double PayOff(double z, double k, bool isCall) const = 0;
    virtual string getClasseName() const = 0;

    double GetS() const;
    double GetUp() const;
    double GetDown() const;
    double GetR() const;
    double GetK() const;
    double GetSigma() const;
    double GetT() const;
    bool GetWay() const;





private:
    double r,k,s,t,sigma,up,down;
    bool way;

};






#endif // _OPTION_HPP
