#include "MonteCarlo.hpp"


MonteCarlo::MonteCarlo(const Option& op, double n ) : opt(op)
{
    this->nSimu = n;
    this->r = opt.GetR();
    this->sigma = op.GetSigma();
    this->k = op.GetK();
    this->S =op.GetS();
    this->T = op.GetT();
    this->way = op.GetWay();

   // cout << "r " << r << " sigma " << sigma << " s "  << S << endl;

}


MonteCarlo::MonteCarlo(const Option& op, double r, double si, double k, double s, double t, double n, bool way) : opt(op)
{
    this->r = r;
    this->sigma = si;
    this->k = k;
    this->S =s;
    this->T = t;
    this->nSimu = n;
    this->way = way;



}

double MonteCarlo::computeAsset()
{

  //  std::random_device rd;
   // std::mt19937 gen(rd());
    std::normal_distribution<> N(0,1);

    double gauss = N(generator);
    //cout << gauss << endl;
    double res = S*exp( (r-pow(sigma,2)*0.5) * T + sigma*sqrt(T)*gauss);
    return res;
}



double MonteCarlo::call_payOff(double ST,double K)
{
    return max(0.0, ST- K);
}

double MonteCarlo::put_payOff(double ST,double K)
{
    return max(0.0, K-ST);
}


double MonteCarlo::sumVector(vector<double> vect)
{
    double sum = 0.0;

    for(int i=0; i< vect.size(); i++)
    {
        sum += vect[i];
        //cout << vect[i] << endl;
    }

    return sum;
}

double MonteCarlo::simulate()
{
    for(int i=0; i< this->nSimu; i++)
    {
        double st = this->computeAsset();
        double payOff = opt.PayOff(st,this->k,way);
        //cout << "po " << payOff << endl;
        this->value.push_back(payOff);
    }

    double factor = exp(-1*this->r*this->T);

    double price = factor * this->sumVector(this->value) / (double)this->nSimu ;

    return price;
}

