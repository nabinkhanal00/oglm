#include <iostream>

#include "mat4.hpp"

template<class T>
T* Mat4<T>::operator [] (int n){
    return _mat[n];
}

template<class T>
Mat4<T> Mat4<T>::operator + (const Mat4<T>& mat1){
    Mat4 sum;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            sum[i][j] = mat1._mat[i][j] + this->_mat[i][j];
        }
    }

    return sum;
}

template<class T>
Mat4<T> Mat4<T>::operator - (const Mat4& mat1){
    Mat4 diff;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            diff[i][j] = this->_mat[i][j] - mat1._mat[i][j];
        }
    }

    return diff;
}

template<class T>
Mat4<T>::Mat4(
        T a1, T a2, T a3, T a4,
        T b1, T b2, T b3, T b4,
        T c1, T c2, T c3, T c4,
        T d1, T d2, T d3, T d4
    ){
        _mat[0][0] = a1;
        _mat[0][1] = a2;
        _mat[0][2] = a3;
        _mat[0][3] = a4;
        _mat[1][0] = b1;
        _mat[1][1] = b2;
        _mat[1][2] = b3;
        _mat[1][3] = b4;        
        _mat[2][0] = c1;
        _mat[2][1] = c2;
        _mat[2][2] = c3;
        _mat[2][3] = c4;
        _mat[3][0] = d1;
        _mat[3][1] = d2;
        _mat[3][2] = d3;
        _mat[3][3] = d4;
}



template<class T>
Mat4<T>::Mat4(){}

template<class T>
std::ostream& operator<<(std::ostream& os, const Mat4<T>& matrix){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            os << matrix._mat[i][j] << "\t";
        }
        os << "\n";
    }
    return os;
}