#pragma once
#include <iostream>
#include "vec3.hpp"
namespace oglm {
template <class T> class _mat3 {
  private:
	T _mat[3][3];

  public:
	_mat3(T d = 1) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == j)
					_mat[i][j] = d;
				else
					_mat[i][j] = 0;
			}
		}
	}

	T *operator[](int n) { return _mat[n]; }

	_mat3<T> operator+(const _mat3 &mat1) {
		_mat3 sum;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				sum[i][j] = mat1._mat[i][j] + this->_mat[i][j];
			}
		}

		return sum;
	}

	_mat3<T> operator-(const _mat3 &mat1) {
		_mat3 diff;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				diff[i][j] = this->_mat[i][j] - mat1._mat[i][j];
			}
		}

		return diff;
	}

	friend std::ostream &operator<<(std::ostream &os, const _mat3<T> &matrix) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				os << matrix._mat[i][j] << "\t";
			}
			os << "\n";
		}
		return os;
	}

	friend std::istream &operator>>(std::istream &is, _mat3<T> &matrix) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				is >> matrix._mat[i][j];
			}
		}
		return is;
	}

	_mat3<T> operator*(const T left) {
		_mat3<T> result;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				result[i][j] = left * _mat[i][j];
			}
		}
		return result;
	}

	_vec3<T> operator*(const _vec3<T> &right) {
		_vec3<T> result;
		for (int i = 0; i < 3; i++) {
			T sum = 0;
			for (int j = 0; j < 3; j++) {
				sum += _mat[i][j] * right[j];
			}
			result[i] = sum;
		}

		return result;
	}

	_mat3<T> operator*(const _mat3<T> &right) {
		_mat3<T> result;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				T total = 0;
				for (int k = 0; k < 3; k++) {
					total += _mat[i][k] * right._mat[k][j];
				}
				result[i][j] = total;
			}
		}

		return result;
	}

	bool operator==(const _mat3 &right) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (right._mat[i][j] != _mat[i][j])
					return false;
			}
		}

		return true;
	}
};

using mat3 = _mat3<float>;
using mat3f = _mat3<float>;
using mat3i = _mat3<int>;
using mat3u = _mat3<unsigned int>;
} // namespace oglm
