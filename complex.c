#include <math.h>

typedef struct {float Re, Im} complex;

    complex c_add(complex z1, complex z2) // z1+z2
    {
        complex result;
        result.Re = z1.Re + z2.Re;
        result.Im = z1.Im + z2.Im;
        return result;
    }

    complex c_sub(complex z1, complex z2) // z1-z2
    {
        complex result;
        result.Re = z1.Re - z2.Re;
        result.Im = z1.Im - z2.Im;
        return result;
    }

    float c_module(complex z1) // |z|
    {
        float result = sqrt(z1.Re*z1.Re+z1.Im*z1.Im);
        return result;
    }

    complex c_conjugate(complex z1){ // комплексно сопряженное
        complex result = {z1.Re, -z1.Im};
        return result;
    }

    // complex c_multiply(complex z1, complex z2)
    // {
    //     complex result;
    //      result = ...
    
    // }
