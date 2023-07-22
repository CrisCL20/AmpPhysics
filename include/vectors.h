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

template <class T>
double Vector::vector<T>::norm() {
    return sqrt((x * x) + (y * y) + (z * z));
}

template <class T>
void Vector::vector<T>::print() {
    (z==0) ?
    std::cout << x << "i + " << y << "j\n" : 
    std::cout << x << "i + " << y << "j + " << z << "k\n";

}

template <class T>
T Vector::vector<T>::getx() {
    return x;
}


template <class T>
T Vector::vector<T>::gety() {
    return y;
}


template <class T>
T Vector::vector<T>::getz() {
    return z;
}

template <class T>
Vector::vector<T> Vector::vector<T>::unitary() {
    return Vector::vector<T>(x/norm(),y/norm(),z/norm());
}

template <class T>
Vector::vector<T> Vector::vector<T>::operator+(Vector::vector<T> b) {
    return vector<T>(x+b.x,y+b.y,z+b.z);
}

template <class T>
T Vector::vector<T>::operator*(Vector::vector<T> b) {
    return x * b.x + y * b.y + z * b.z;
}

template <class T>
Vector::vector<T> Vector::vector<T>::operator*(double k){
    return Vector::vector<T>(k*x,k*y,k*z);
}

#endif
