#include "vectors.h"

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
