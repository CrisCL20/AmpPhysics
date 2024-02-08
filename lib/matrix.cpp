#include <matrix.h>
#include <Except.hpp>
#include <stdlib.h>
#include <iostream>

template <typename U>
Matrix::matrix<U>::matrix(const std::size_t nrows, const std::size_t ncols) {
    nRows = nrows;
    nCols = ncols;
    const std::size_t N = nRows * nCols;
    matdata = new U[N];
    for(size_t i = 1; i <= N; ++i)
        matdata[i] = 0;
}

template <typename U>
Matrix::matrix<U>::matrix() {
  matdata = 0x0;
}

template <typename U>
void Matrix::matrix<U>::print()
{
  for(std::size_t i=1;i <= nRows; ++i){
    for(std::size_t j=1; j <= nCols; ++j)
      std::cout << matdata[(i-1)*nCols+j] << ", ";
    std::cout << std::endl;
  }
}

template <typename U>
Matrix::matrix<U> Matrix::matrix<U>::transpose() {
    
    Matrix::matrix<U> B(nCols,nRows);
    for(std::size_t i = 1; i <= nRows; ++i)
        for(std::size_t j = 1; j <= nCols;++j)
            B.matdata[(i-1)*nCols+j] = matdata[(j-1)*nRows+i];
        
    return B;
}

template <typename U>
Matrix::matrix<U> Matrix::matrix<U>::operator+(Matrix::matrix<U> B) {
   
    if( (nRows != B.nRows) || (nCols != B.nCols))
    {
      throw Except("Cannot perform matrix addition\n");
      exit(0);
    }

    Matrix::matrix<U> C(nRows,nCols);

    for(size_t i = 1; i <= nRows; ++i) 
        for(size_t j = 1; j <= nCols; ++j)
            C.putData(i,j,matdata[(i-1)*nCols + j] + B.matdata[(i-1)*nCols + j]);
    return C;     
    
}

template<typename U>
Matrix::matrix<U> Matrix::matrix<U>::operator*(Matrix::matrix<U> B) 
{ 
  if(nCols != B.nRows)
  {

    throw Except("Can not perform matrix multiplication\n");
    exit(0);
  }

  Matrix::matrix<U> C(nRows,B.nCols);
  
  for(std::size_t i = 1; i <= nRows; ++i) 
    for(std::size_t j = 1; j <= B.nCols; ++j) 
      for(std::size_t k = 1; k <= B.nRows; ++k)
        C.matdata[(i-1)*B.nCols + j] += matdata[(i-1)*nCols + k] * B.matdata[(k-1)*nCols + j]; 

  return C;
}

template<typename U>
Matrix::matrix<U> Matrix::matrix<U>::operator&(Matrix::matrix<U> B)
{
  if(nRows != B.nRows || nCols != B.nCols)
  {
    throw Except("Can not perform element-wise multiplication\n");
    exit(0);
  }

  Matrix::matrix<U> C(nRows,nCols);
  for(std::size_t i = 1; i <= nRows; ++i)
    for(std::size_t j = 1; j <= nCols; ++j)
      C.putData(i,j,matdata[(i-1)*nRows+j] * B.getMatData()[(i-1)*nRows+j]);

  return C;
} 

template<typename U>
U *Matrix::matrix<U>::getMatData()
{
  return this->matdata;
}

template<typename U>
void Matrix::matrix<U>::putData(const std::size_t i, const std::size_t j, const U dat)
{
  this->matdata[(i-1)*this->nRows + j] = dat;
}

const Matrix::matrix<bool> indentity(const std::size_t dim)
{
  Matrix::matrix<bool> I(dim,dim); 
  for(std::size_t i = 1; i <= dim; ++i)
    for(std::size_t j = 1; j <= dim; ++j)
      if(i == j)
        I.putData(i,j,1);
  return I;
} 

template<typename U>
void Matrix::matrix<U>::ones()
{
  const std::size_t n = nRows*nCols;
  for(std::size_t i = 1; i <= n; ++i)
    matdata[i] = 1; 
}

template<typename U>
void Matrix::matrix<U>::fill(const U n)
{
  const std::size_t N = nRows*nCols;
  for(std::size_t i = 1; i <= N; ++i)
    matdata[i] = n; 
}

template class Matrix::matrix<int>;
template class Matrix::matrix<float>;
template class Matrix::matrix<double>;

