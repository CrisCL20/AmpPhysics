#ifndef MATRIX_H
#define MATRIX_H

namespace linear {
    template <class U>
    class matrix {
        public:
            matrix(int nrows,int ncols); //creates matrix filled with zeros.

            double det();
            matrix inv();
            matrix T(); 

            matrix operator+(matrix other);
            matrix operator*(matrix other);
            matrix operator*(const double k); 

        private:
            int nRows;
            int nCols;
            U* matdata; //array with matrix data
    };

    const matrix<int> identity(int dim); //generates the identity matrix on dim x dim. 
}

#endif