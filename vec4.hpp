#pragma once

#include <cmath>
#include <iostream>

namespace oglm {

template <typename T = float> class _vec4 {
  public:
	_vec4() : x(0), y(0), z(0), w(0) {}

	_vec4(T e0, T e1, T e2, T e3) : x(e0), y(e1), z(e2), w(e3) {}

	_vec4 operator-() const { return _vec4(-x, -y, -z, -w); }

	_vec4 &operator+=(const _vec4 &v) {
		x += v.x;
		y += v.y;
		z += v.z;
		w += v.w;
		return *this;
	}

	_vec4 &operator-=(const _vec4 &v) {
		x -= v.x;
		y -= v.y;
		z -= v.z;
		w -= v.w;
		return *this;
	}

	_vec4 &operator*=(const float &t) {
		x *= t;
		y *= t;
		z *= t;
		w *= t;
		return *this;
	}

	_vec4 &operator/=(const float &t) {
		x /= t;
		y /= t;
		z /= t;
		w /= t;
		return *this;
	}

	_vec4 operator/(float t) { return _vec4(x / t, y / t, z / t, w / t); }

	T length() const { return std::sqrt(length_squared()); }

	T length_squared() const { return x * x + y * y + z * z + w * w; }

	const T &operator[](const unsigned int &i) const {
		if (i == 0)
			return x;
		else if (i == 1)
			return y;
		else if (i == 2)
			return z;
		else if (i == 3)
			return w;
		else
			throw("Index out of range");
	}
	T &operator[](const unsigned int &i) {
		if (i == 0)
			return x;
		else if (i == 1)
			return y;
		else if (i == 2)
			return z;
		else if (i == 3)
			return w;
		else
			throw("Index out of range");
	}

  public:
	T x, y, z, w;
};

template <typename T>
static std::ostream &operator<<(std::ostream &out, const _vec4<T> &v) {
	return out << v.x << " " << v.y << " " << v.z << " " << v.w;
}
template <typename T>
static std::istream &operator>>(std::istream &in, _vec4<T> &v) {
	return in >> v.x >> v.y >> v.z >> v.w;
}
template <typename T>
static _vec4<T> operator+(const _vec4<T> &u, const _vec4<T> &v) {
	return _vec4<T>(u.x + v.x, u.y + v.y, u.z + v.z, u.w + v.w);
}
template <typename T>
static _vec4<T> operator-(const _vec4<T> &u, const _vec4<T> &v) {
	return _vec4<T>(u.x - v.x, u.y - v.y, u.z - v.z, u.w - v.w);
}
template <typename T> static _vec4<T> operator*(const _vec4<T> &u, float t) {
	return _vec4<T>(t * u.x, t * u.y, t * u.z, t * u.w);
}
template <typename T>
static _vec4<T> operator*(const float &t, const _vec4<T> &v) {
	return _vec4<T>(t * v.x, t * v.y, t * v.z, t * v.w);
}

using vec4ui = _vec4<unsigned int>;
using vec4i = _vec4<int>;
using vec4f = _vec4<float>;
using vec4 = _vec4<float>;
using vec4d = _vec4<double>;

} // namespace oglm
