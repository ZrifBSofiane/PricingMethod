#ifndef CRR_H
#define CRR_H


class Crr
{
    public:
        Crr();
        virtual ~Crr();

        double GetS() { return S; }
        void SetS(double val) { S = val; }
        double GetH() { return H; }
        void SetH(double val) { H = val; }

    protected:

    private:
        double S;
        double H;
};

#endif // CRR_H
