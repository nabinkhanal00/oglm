#pragma once
#include <iostream>
#include <cmath>
#include "vec2.hpp"
#include "vec3.hpp"
template <class T>
class Mat4{
    private:
    T _mat[4][4]; 

    public:
    Mat4(
        T a1, T a2, T a3, T a4,
        T b1, T b2, T b3, T b4,
        T c1, T c2, T c3, T c4,
        T d1, T d2, T d3, T d4
    );

    Mat4(T data);
    Mat4();

    T* operator [] (int n);
    Mat4<T> operator + (const Mat4& mat1);
    Mat4<T> operator - (const Mat4& mat1);
    Mat4<T> operator * (const Mat4& right);
    bool operator == (const Mat4& right);

    template <typename U>
    Mat4<T> operator * (U right);
    
    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const Mat4<U>& matrix);

    template<typename U>
    friend std::istream& operator>>(std::istream& is, Mat4<U>& matrix);
    
    template<typename U>
    friend Mat4<U> operator*(U left, const Mat4<U>& matrix);
};
