#ifndef MATRIX_H
#define MATRIX_H

namespace Matrix {
    template <class U>
    class matrix {
        public:
            matrix(int nrows,int ncols); //creates matrix filled with zeros.

            ~matrix();

            double det();
            matrix<double> inv();
            matrix<U> T(); 

            matrix<U> operator+(matrix<U> other);
            matrix<U> operator*(matrix<U> other);
            matrix<U> operator*(const double k); 

        private:
            int nRows;
            int nCols;
            U* matdata; //array with matrix data
    };

    const matrix<int> identity(int dim); //generates the identity matrix on dim x dim. 
}

#endif