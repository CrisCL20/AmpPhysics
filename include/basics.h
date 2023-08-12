#ifndef BASICS_H
#define BASICS_H

#include "vectors.h"
#include <cmath>

namespace types{
    class integer {
        public:
            integer(int n);
            void print();    
        private:
            int x;
    };

    class complex {
        public:
            complex(double re_, double im_);

            Vector::vector<double> argand_vec();
            double mod();
            complex polar();
            complex conj();
            complex reciprocal();
            double ln();

            void setr();
            void setang();

            double getRe();
            double getIm();

            complex operator+(complex other);
            complex operator*(complex other);
            complex operator/(complex other);
            

        private:
            double re;
            double im;
            double r;
            double ang; 
    };


}


#endif