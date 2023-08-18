#ifndef QUADRATURE_H
#define QUADRATURE_H

#define n 10000

namespace methods{
    double simpson(double (*f)(double), double A, double B);
    
    //for integrals that go from -inf to x
    double gauss_laguerre(double (*f)(double),double x); 
}

#endif