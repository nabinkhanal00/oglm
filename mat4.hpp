#pragma once
#include "vec4.hpp"
#include <iostream>
namespace oglm {
template <class T> class _mat4 {
  private:
	T _mat[4][4];

  public:
	_mat4(T d = 1) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (i == j)
					_mat[i][j] = d;
				else
					_mat[i][j] = 0;
			}
		}
	}

	T *operator[](int n) { return _mat[n]; }

	_mat4<T> operator+(const _mat4 &mat1) {
		_mat4 sum;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				sum[i][j] = mat1._mat[i][j] + this->_mat[i][j];
			}
		}

		return sum;
	}

	_mat4<T> operator-(const _mat4 &mat1) {
		_mat4 diff;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				diff[i][j] = this->_mat[i][j] - mat1._mat[i][j];
			}
		}

		return diff;
	}

	friend std::ostream &operator<<(std::ostream &os, const _mat4<T> &matrix) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				os << matrix._mat[i][j] << "\t";
			}
			os << "\n";
		}
		return os;
	}

	friend std::istream &operator>>(std::istream &is, _mat4<T> &matrix) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				is >> matrix._mat[i][j];
			}
		}
		return is;
	}

	_mat4<T> operator*(const T left) {
		_mat4<T> result;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				result[i][j] = left * _mat[i][j];
			}
		}
		return result;
	}

	_vec4<T> operator*(const _vec4<T> &right) {
		_vec4<T> result;
		for (int i = 0; i < 4; i++) {
			T sum = 0;
			for (int j = 0; j < 4; j++) {
				sum += _mat[i][j] * right[j];
			}
			result[i] = sum;
		}

		return result;
	}

	_mat4<T> operator*(_mat4<T> &right) {
		_mat4<T> result;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				T total = 0;
				for (int k = 0; k < 4; k++) {
					total += _mat[i][k] * right._mat[k][j];
				}
				result[i][j] = total;
			}
		}

		return result;
	}

	bool operator==(const _mat4 &right) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (right._mat[i][j] != _mat[i][j])
					return false;
			}
		}

		return true;
	}
};

using mat4 = _mat4<float>;
using mat4f = _mat4<float>;
using mat4i = _mat4<int>;
using mat4u = _mat4<unsigned int>;
} // namespace oglm
