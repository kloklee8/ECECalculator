#include "Divider.hpp"

void Divider::divideVoltage(const double vs, const double r1, const double r2, double* vr1, double* vr2)
{
    *vr1 = vs * r1/(r1+r2);
    *vr2 = vs * r2/(r1+r2);
}

void Divider::divideCurrent(const double is, const double r1, const double r2, double* ir1, double* ir2)
{
    *ir1 = is * r2/(r1+r2);
    *ir2 = is * r1/(r1+r2);
}
