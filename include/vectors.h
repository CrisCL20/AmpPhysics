#ifndef VECTORS_H_
#define VECTORS_H_

#include <cmath>

namespace Vector {
template <class T>
class vector {
public:
    vector(T x, T y) : x(x),y(y) {}
    vector(T x, T y, T z) : x(x),y(y),z(z) {}
    ~vector() {}
    double norm();
    void print();
    template<class U> friend vector<U> operator+(vector<U> a, vector<U> b);
    template<class M> friend M operator* ( vector<M> a, vector<M> b); //dot product
    
private:
    T x,y,z {0};
};
}

#endif
