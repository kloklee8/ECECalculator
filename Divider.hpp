#ifndef DIVIDER_H
#define DIVIDER_H

class Divider
{
    public:
        Divider();
        void divideCurrent(double vs, double r1, double r2, double* vr1, double* vr2);
        void divideVoltage(double is, double r1, double r2, double* ir1, double* ir2);
    private:
    
};

#endif
