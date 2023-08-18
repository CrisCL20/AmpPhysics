#include "quadrature.h"
#include <cstddef>

double methods::simpson(double (*f)(double),double A, double B) {
    const double h = (B-A)/n;

    double x_0 = A,
           x_1 = A+h,
           x_2 = A+2*h,
           x_n = B,
           x_it1,
           x_it2;
    double res = f(x_0) + f(x_n),
           it_1 = f(x_1), 
           it_2 = f(x_2);

    for(size_t i = 2; i <= n/2; ++i) {
        x_it1 = A+(2*i-1)*h;
        it_1 += f(x_it1);
    }

    it_1 = 4*it_1;

    for(size_t i = 0; i <= (n/2) - 1; ++i) {
        x_it2 = A + (2*i)*h;
        it_2 += f(x_it2);
    }

    it_2 = 2*it_2;

    return (1/3)*h * (res+it_1+it_2);
    
}

double new_f(double (*f)(double),double a,double t) {
    return f(a-((1-t)/t)) * (1/(t*t));
}
/*
* @todo implement integration on semi infinite intervals
* @details https://en.wikipedia.org/wiki/Numerical_integration
*/
double methods::gauss_laguerre(double (*f)(double), double x) {
    
    //return methods::simpson(new_f(f,0,),0,1);
}