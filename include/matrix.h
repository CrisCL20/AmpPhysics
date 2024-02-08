#pragma once

#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <memory>

namespace Matrix {
    template <typename U>
    class matrix {
        public:
            matrix(const std::size_t nrows,const std::size_t ncols); //creates matrix filled with zeros.
            matrix();          

            ~matrix() {}
            
            /* Common matrix characteristics and properties */
            void print(); 
            void ones(); //fills matrix A with ones 
            void fill(const U n);
            double determinant();
            matrix<double> inverse();
            matrix<U> transpose(); 
            
            /* Usefull operators */
            
            matrix<U> operator+(const matrix<U> B);
            matrix<U> operator*(matrix<U> B); //dot product
            matrix<U> operator&(matrix<U> B); //element-wise multiplication (essential for Hadammart product)

            U *getMatData();
            void putData(const std::size_t i, const std::size_t j, const U dat);

        private:
            std::size_t nRows;
            std::size_t nCols;
            U *matdata; //array with matrix data
    };

    const matrix<bool> identity(const int dim); //generates the identity matrix on dim x dim. 
    
    
}

#endif
