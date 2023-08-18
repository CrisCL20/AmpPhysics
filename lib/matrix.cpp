#include <cstddef>
#include "matrix.h"

template <class T>
Matrix::matrix<T>::matrix(int nrows, int ncols) {
    nRows = nrows;
    nCols = ncols;
    const int N = nRows * nCols;
    for(size_t i = 0; i < N; ++i)
        matdata[i] = 0.0;
}

template <class T>
Matrix::matrix<T>::~matrix() {
    delete[] matdata * (matdata!=NULL);
}

template <class U>
Matrix::matrix<U> Matrix::matrix<U>::T() {
    
    Matrix::matrix<U> B(nCols,nRows);
    for(size_t i = 0; i < nRows; ++i)
        for(size_t j = 0; j < nCols;++j)
            B.matdata[i+j*nCols] = matdata[j+i*nRows];
        
    return B;
}

template <class U>
Matrix::matrix<U> Matrix::matrix<U>::operator+(Matrix::matrix<U> other) {
    
    int rows = Matrix::matrix<U>::getRows();
    int cols = other.nCols;

    Matrix::matrix<U> C;

    C.nRows = rows;
    C.nCols = cols;
    
    for(size_t i = 0; i < rows; ++i) 
        for(size_t j = 0; j < cols; ++j)
            C.matdata[i+j*cols] = matdata[i+j*cols] + other.matdata[i+j*cols];
        
    
}
