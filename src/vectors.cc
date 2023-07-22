#include "vectors.h"

namespace Vector { 
    template <class T> 
    void vector<T>::vector(T x, T y) : x(x), y(y) {}

    template<class T>
    void vector<T>::vector(T x, T y, T z) : x(x), y(y), z(z) {}

    template <class T>
    double vector<T>::norm() {
        return sqrt((x * x) + (y * y) + (z * z));
    }

    template <class T>
    vector<T> operator+(vector<T> a, vector<T> b) {
        return new vector<T>(a.x+b.x,a.y+b.y);
    }

    template <class T>
    vector<T> operator+(vector<T> a, vector<T> b) {
        return new vector<T>(a.x+b.x,a.y+b.y,a.z+b.z);
    }

    template <class T>
    T operator*(vector<T> a, vector<T> b) {
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }

}