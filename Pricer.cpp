#include "Pricer.hpp"

Pricer::Pricer(const Option& op, double n ) : opt(op)
{

    this->nDeep = n;

}




// **************************** Factorial function ********************
int Pricer::fact(int n)
{
    if(n==0)
        return 1;
    else
        return n * fact(n-1);
}
// **************************** END Factorial function ********************




vector<double> Pricer::CrrMethod()
{
    // ****************************   CRR TD5 *************************************


    int deep =(int)this->opt.GetT();


  //  cout << endl << "Creation of vector size " << deep << endl;

    double S0 = 100;
    double up = 3;
    double down = 2;
    double r = 2.5;
    double k = 95;



    S0 = this->opt.GetS();

    up = this->opt.GetUp();

    down = this->opt.GetDown();

    r= this->opt.GetR();

    k = this->opt.GetK();

    bool way = this->opt.GetWay();
    double q = (r -down)/(up - down);
   // cout << "q "<< q << endl;

    vector<vector<Crr*>> vectorCrr;


// **************************** TREE CREATION ********************


    for(int n=0; n<deep; n++)
    {
        vector<Crr*> tempCrrVector;

        for(int i=0;i<=n; i++)
        {
            Crr *tempCrr = new Crr();
            double valueS = tempCrr->ComputeS(S0,up,down,n,i);
            tempCrr->SetS(valueS);
            if(n == deep-1)
            {
               // valueS = tempCrr->ComputeH(k,valueS,way);
               //cout << "value " << valueS << " k " << k ;
                valueS = this->opt.PayOff(valueS,k,way);
                tempCrr->SetH(valueS);
                //cout << " h " << valueS << endl;
            }
            tempCrrVector.push_back(tempCrr);
        }

        vectorCrr.push_back(tempCrrVector);
    }
// **************************** END TREE CREATION ********************


// **************************** COMPUTE H FOR ALL NODE ********************
    for(int n=(deep-1)-1; n>=0; n--)
    {
        for(int i=0;i<=n; i++)
        {
            Crr *CrrSetH = vectorCrr[n][i];
            Crr *CrrI1 = vectorCrr[n+1][i+1];
            Crr *CrrI = vectorCrr[n+1][i];
            double value1 = CrrI1->GetH();
            double value2 = CrrI->GetH();

            if(this->opt.getClasseName() == "AmericanOption")
                CrrSetH->SetH(max((q*value1+(1-q)*value2)/(1+r),CrrSetH->GetS()));
            else
                CrrSetH->SetH((q*value1+(1-q)*value2)/(1+r));

        }
    }




// **************************** CLOSED FORM FORMULA ********************
    double closedFormula = (double)0;
    double sum = (double)0;
    for(int i=0 ; i< deep; i++)
    {
        Crr *CrrTemp = vectorCrr[deep-1][i];
        double HSni = CrrTemp->GetH();
        //cout << "sum : " << sum << endl;
        double a = (double)this->fact(deep-1);
        double b = (double)this->fact(i);
        double c = (double)this->fact(deep-1-i);
       // cout << "a " << a << " b " << b << " c " << c << endl;
        sum += (a)/(b*c) * (double)pow(q,i) * (double)pow(1-q,deep-1-i) * HSni;
       // cout << "sum : " << sum << endl;
    }
    closedFormula = (1/ pow(1+r,deep-1)) * sum;
// **************************** END CLOSED FORM FORMULA ********************






// **************************** DISPLAY TREE  ********************
    for(int n=0; n<deep; n++)
    {
        vector<Crr*> tempCrrVector = vectorCrr[n];

        for(int i=0;i<=n; i++)
        {
            Crr *tempCrr = tempCrrVector[i];
            cout << "Step : " << n  << " Node : "<<  i << "   S : " << tempCrr->GetS() << "   H : "<< tempCrr->GetH()<< endl;
        }
    }
// **************************** END DISPLAY TREE  ********************



// **************************** SHOW RESULTS  ********************
    Crr *CrrResult = vectorCrr[0][0];

// **************************** END SHOW RESULTS  ********************


// **************************** END CRR TD5 *************************************
    vector<double> result;
    result.push_back(CrrResult->GetH());
    result.push_back(closedFormula);

    return result;
}






