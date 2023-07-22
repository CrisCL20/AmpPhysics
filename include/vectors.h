#ifndef VECTORS_H_
#define VECTORS_H_

#include <cmath>
#include <iostream>

namespace Vector {
template <class T>
class vector {
public:
    vector(T x_, T y_) : x(x_),y(y_) {}
    vector(T x_, T y_, T z_) : x(x_),y(y_),z(z_) {}
    ~vector() {}

    double norm();
    void print();
    T getx();
    T gety();
    T getz();

    template<class U> friend vector<U> operator+(vector<U> a, vector<U> b);
    template<class M> friend M operator* ( vector<M> a, vector<M> b); //dot product
    
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

template <class U>
Vector::vector<U> operator+(Vector::vector<U> a, Vector::vector<U> b) {
    return new 
        Vector::vector<U>(a.x+b.x,a.y+b.y,a.z+b.z);
}

template <class M> 
M operator*(Vector::vector<M> a, Vector::vector<M> b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

#endif
