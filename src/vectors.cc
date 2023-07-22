#include "vectors.h"
#include "iostream"

using namespace std;

namespace Vector { 

    template <class T>
    double vector<T>::norm() {
        return sqrt((x * x) + (y * y) + (z * z));
    }

    template <class T>
    void vector<T>::print() {
        cout << x << "i + " << y << "j + " << z << "k\n";
    }

    template <class U>
    vector<U> operator+(vector<U> a, vector<U> b) {
        return new 
            vector<U>(a.x+b.x,a.y+b.y,a.z+b.z);
    }

    template <class M> 
    M operator*(vector<M> a, vector<M> b) {
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }

}
