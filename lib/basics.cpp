#include "basics.h"
#include <iostream>

types::integer::integer(int n) : x(n) {}

void types::integer::print() {
    std::cout << x << std::endl;
}

types::complex::complex(double re_,double im_) : re(re_) , im(im_) {}

Vector::vector<double> types::complex::argand_vec() {
    return Vector::vector<double>(re,im);
}

double types::complex::mod() {
    return sqrtl(re*re + im*im);
}

types::complex types::complex::polar() {
    if(ang == 0)
        return types::complex(0,0);

    return types::complex(r*cos(ang),r*sin(ang));    
}

types::complex types::complex::conj() {
    return types::complex(re,-1*im);
}

types::complex types::complex::reciprocal() {
    return types::complex(re/pow(mod(),2.),-1*im/pow(mod(),2.));
}

double types::complex::ln() {
    return log(r) + ang;
}

void types::complex::setr() {
    r = mod();
}

void types::complex::setang() {
    ang = 2*atan(im / (re + mod())) * (im!=0 || re>0) 
                         + M_PI * (re < 0 && im==0)
                         + 0 * (re==0 && im ==0);
}

double types::complex::getRe(){
    return re;
}

double types::complex::getIm() {
    return im;
}

types::complex types::complex::operator+(types::complex other) {
    return complex(re+other.re,im+other.im);
}

types::complex types::complex::operator*(types::complex other) {
    return types::complex(re*other.re - im*other.im,re*other.im + im*other.re);
}

types::complex types::complex::operator/(types::complex other) {
    return *this * other.reciprocal();
}