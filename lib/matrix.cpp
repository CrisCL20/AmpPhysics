#include "matrix.h"

template <class T>
Matrix::matrix<T>::matrix(int nrows, int ncols) {
    nRows = nrows;
    nCols = ncols;
    const int N = nRows * nCols;
    T* matdata = new T[N];
    for(size_t i = 0; i < N; ++i)
        matdata[i] = 0.0;
}

template <class T>
Matrix::matrix<T>::~matrix() {
    delete[] matdata * (matdata!=NULL);
}

template <class U>
Matrix::matrix<U>::T() {
    
    Matrix::matrix<U> B(nCols,nRows);
    for(size_t i = 0; i < nRows; ++i)
        for(size_t j = 0; j < nCols;++j)
            B.matdata[i+j*nCols] = matdata[j+i*nRows]; 
}

template <class T>
Matrix::matrix<T> Matrix::matrix<T>::operator+(Matrix::matrix<T> other) {}