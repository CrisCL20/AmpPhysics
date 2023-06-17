#include <cmath>


namespace Vector {


template <class T>
class Vector {
public:
    void Vector(T x, T y) : x(x), y(y) {}

    void Vector(T x, T y, T z) : x(x), y(y), z(z) {}

    double norm2d() {
        return sqrt((this->x * this->x) + (this->y * this->y)) 
    }

    double norm3d() {
        return sqrt((this->x * this->x) + (this->y * this->y) + (this->z * this->z))
    }

    template<class U> friend static Vector<U> operator+(Vector<U> a, Vector<U> b) {
        return new Vector(a.x+b.x,a.y+b.y);
    }

    template<class U> friend static Vector<U> operator+(Vector<U> a, Vector<U> b) {
        return new Vector(a.x+b.x,a.y+b.y,a.z+b.z);
    }

    template<class U> friend U operator* ( Vector<U> a, Vector<U> b) { //dot product
        return a.x * b.x  + a.y * b.y;
    }

    template<class U> friend U operator* ( Vector<U> a, Vector<U> b) { //dot product
        return a.x * b.x  + a.y * b.y + a.z * b.z;
    }

private:
    double ang;
    T x,y,z;
};
}