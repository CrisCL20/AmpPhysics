#include <cmath>


namespace Vector {


template <class T>
class R2Vector {

public:
    void R2Vector(T x, T y) {
        this->ang = ang;
        this->x = x; this->y = y;
    }


    double norm() {
        return sqrt((this->x * this->x) + (this->y * this->y)) 
    }

    template<class U> friend static R2Vector<U> operator+(R2Vector<U> a, R2Vector<U> b) {
        return new R2Vector(a.x+b.x,a.y+b.y);
    }

    template<class U> friend U operator* ( R2Vector<U> a, R2Vector<U> b) { //dot product
        return a.x * b.x  + a.y * b.y;
    }

private:
    double ang;
    T x,y;
};
}