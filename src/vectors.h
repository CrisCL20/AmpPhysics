#ifndef VECTORS_H_
#define VECTORS_H_

#include <cmath>

namespace Vector {
template <class T>
class vector {
public:
    void vector(T x, T y);

    void vector(T x, T y, T z);
    ~vector() {}
    double norm2d();
    double norm3d();
    template<class U> friend static vector<U> operator+(vector<U> a, vector<U> b);
    template<class U> friend static vector<U> operator+(vector<U> a, vector<U> b);
    template<class U> friend U operator* ( vector<U> a, vector<U> b); //dot product
    template<class U> friend U operator* ( vector<U> a, vector<U> b); //dot product

private:
    double ang;
    T x,y,z;
};
}

#endif
