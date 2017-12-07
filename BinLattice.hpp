#ifndef _BINLATTICE_HPP
#define _BINLATTICE_HPP

#include <iostream>
#include <vector>



using namespace std;

template <class T>
class BinLattice {

public:
    BinLattice();
    void SetN(int n);
    int GetN();
    void SetNode(int step, int node,const T& value);
    T GetNode(int step, int node);
    void Display();



private:
    int N;
    vector<vector<T>> Lattice;

};


template<typename T>
BinLattice<T>::BinLattice()
{
}

template<typename T>
void BinLattice<T>::SetN(int n)
{
    this->N = n;

    for(int step=0; step<this->N; step++)
    {
        vector<T> temp;

        for(int node=0; node <=step; node++)
        {
            T tempT;
            temp.push_back(tempT);
        }
        this->Lattice.push_back(temp);
    }
}

template<typename T>
void BinLattice<T>::SetNode(int step, int node,const T& value)
{
    this->Lattice[step][node] = value;
}

template<typename T>
T BinLattice<T>::GetNode(int step, int node)
{
    return this->Lattice[step][node];
}

template<typename T>
void BinLattice<T>::Display()
{

}


template<typename T>
int BinLattice<T>::GetN()
{
    return this->N;
}







#endif // _BINLATTICE_HPP
