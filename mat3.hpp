#pragma once
#include <iostream>
#include <vector>
namespace oglm {
template <class T> class mat3 {
  private:
	T _mat[3][3];

  public:
	mat3(T d = 1) {
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

	mat3<T> operator+(const mat3 &mat1) {
		mat3 sum;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				sum[i][j] = mat1._mat[i][j] + this->_mat[i][j];
			}
		}

		return sum;
	}

	mat3<T> operator-(const mat3 &mat1) {
		mat3 diff;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				diff[i][j] = this->_mat[i][j] - mat1._mat[i][j];
			}
		}

		return diff;
	}

	friend std::ostream &operator<<(std::ostream &os, const mat3<T> &matrix) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				os << matrix._mat[i][j] << "\t";
			}
			os << "\n";
		}
		return os;
	}

	friend std::istream &operator>>(std::istream &is, mat3<T> &matrix) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				is >> matrix._mat[i][j];
			}
		}
		return is;
	}

	mat3<T> operator*(const T left) {
		mat3<T> result;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				result[i][j] = left * _mat[i][j];
			}
		}
		return result;
	}

	std::vector<T> operator*(const std::vector<T> right) {
		std::vector<T> result;
		for (int i = 0; i < 3; i++) {
			T sum = 0;
			for (int j = 0; j < 3; j++) {
				sum += _mat[i][j] * right[j];
			}
			result.push_back(sum);
		}

		return result;
	}

	mat3<T> operator*(const mat3<T> &right) {
		mat3<T> result;
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

	bool operator==(const mat3 &right) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (right._mat[i][j] != _mat[i][j])
					return false;
			}
		}

		return true;
	}
};
} // namespace oglm
