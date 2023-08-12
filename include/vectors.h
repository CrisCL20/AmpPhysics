#ifndef VECTORS_H_
#define VECTORS_H_

#include <cmath>
#include <iostream>

namespace Vector {
template <class T>
class vector {
public:
    vector(T x_, T y_) : x(x_),y(y_) {} //R2
    vector(T x_, T y_, T z_) : x(x_),y(y_),z(z_) {} //R3
    ~vector() {}

    double norm();
    vector<T> unitary();
    void print();
    T getx();
    T gety();
    T getz();

    vector<T> operator+(vector<T> b);
    T operator*(vector<T> b); //dot product
    vector<T> operator*(double k); //scalar product
    
private:
    T x,y,z {0};
};
}

#endif
