#pragma once

#include <cmath>
#include <iostream>
#include "vec2.hpp"

namespace oglm {

template <typename T> class _vec3 {
  public:
	_vec3() : x(0), y(0), z(0) {}

	_vec3(T e0, T e1, T e2) : x(e0), y(e1), z(e2) {}

	_vec3 operator-() const { return _vec3(-x, -y, -z); }

	_vec3 &operator+=(const _vec3 &v) {
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}

	_vec3 &operator-=(const _vec3 &v) {
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}

	_vec3 &operator*=(const float &t) {
		x *= t;
		y *= t;
		z *= t;
		return *this;
	}

	_vec3 &operator/=(const float &t) {
		x /= t;
		y /= t;
		z /= t;
		return *this;
	}

	_vec3 operator/(float t) { return _vec3(x / t, y / t, z / t); }

	T length() const { return std::sqrt(length_squared()); }

	T dot(const _vec3 &v) { return x * v.x + y * v.y + z * v.z; }

	T length_squared() const { return x * x + y * y + z * z; }

	T &operator[](const unsigned int &i) {
		if (i == 0)
			return x;
		else if (i == 1)
			return y;
		else if (i == 2)
			return z;
		else
			throw("Index out of range");
	}
	const T &operator[](const unsigned int &i) const {
		if (i == 0)
			return x;
		else if (i == 1)
			return y;
		else if (i == 2)
			return z;
		else
			throw("Index out of range");
	}

  public:
	T x, y, z;
};

template <typename T>
static std::ostream &operator<<(std::ostream &out, const _vec3<T> &v) {
	return out << v.x << " " << v.y << " " << v.z;
}
template <typename T>
static std::istream &operator>>(std::istream &in, _vec3<T> &v) {
	return in >> v.x >> v.y >> v.z;
}
template <typename T>
static _vec3<T> operator+(const _vec3<T> &u, const _vec3<T> &v) {
	return _vec3<T>(u.x + v.x, u.y + v.y, u.z + v.z);
}
template <typename T>
static _vec3<T> operator-(const _vec3<T> &u, const _vec3<T> &v) {
	return _vec3<T>(u.x - v.x, u.y - v.y, u.z - v.z);
}
template <typename T> static _vec3<T> operator*(const _vec3<T> &u, float t) {
	return _vec3<T>(t * u.x, t * u.y, t * u.z);
}
template <typename T>
static _vec3<T> operator*(const float &t, const _vec3<T> &v) {
	return _vec3<T>(t * v.x, t * v.y, t * v.z);
}
template <typename T> static T dot(const _vec3<T> &u, const _vec3<T> &v) {
	return u.x * v.x + u.y * v.y + u.z * v.z;
}
template <typename T>
static _vec3<T> cross(const _vec3<T> &u, const _vec3<T> &v) {
	return _vec3<T>(u.y * v.z - u.z * v.y, u.z * v.x - u.x * v.z,
	                u.x * v.y - u.y * v.z);
}
template <typename T> static _vec3<T> normalize(const _vec3<T> &u) {
	T oneOverLength = (T)1 / u.length();
	return oneOverLength * _vec3<T>(u.x, u.y, u.z);
}

using vec3ui = _vec3<unsigned int>;
using vec3i = _vec3<int>;
using vec3f = _vec3<float>;
using vec3 = _vec3<float>;
using vec3d = _vec3<double>;

} // namespace oglm
