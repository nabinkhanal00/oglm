#pragma once

#include <cmath>
#include <iostream>

namespace oglm {

template <typename T = float> class _vec2 {
  public:
	_vec2() : x(0), y(0) {}

	_vec2(T e0, T e1) : x(e0), y(e1) {}

	_vec2 operator-() const { return _vec2(-x, -y); }

	_vec2 &operator-=(const _vec2 &v) {
		x += v.x;
		y += v.y;
		return *this;
	}

	T &operator[](const int &i) {
		if (i == 0)
			return x;
		if (i == 1)
			return y;
		throw "Index out of range";
	}
	const T &operator[](const int &i) const {
		if (i == 0)
			return x;
		if (i == 1)
			return y;
		throw "Index out of range";
	}
	_vec2 &operator+=(const _vec2 &v) {
		x += v.x;
		y += v.y;
		return *this;
	}

	_vec2 &operator*=(const float &t) {
		x *= t;
		y *= t;
		return *this;
	}

	_vec2 &operator/=(const float &t) {
		x /= t;
		y /= t;
		return *this;
	}

	_vec2 operator+(const _vec2 &v) { return _vec2(x + v.x, y + v.y); }

	_vec2 operator-(const _vec2 &v) { return _vec2(x - v.x, y - v.y); }

	_vec2 operator*(const float &t) { return _vec2(t * x, t * y); }

	friend _vec2 operator*(const float &t, const _vec2 &v) {
		return _vec2(t * v.x, t * v.y);
	}

	_vec2 operator/(const float &t) { return _vec2(t / x, t / y); }

	_vec2 unit() { return _vec2<T>(x, y) / length(); }

	T length() const { return std::sqrt(length_squared()); }

	T dot(const _vec2 &v) { return x * v.x + y * v.y; }

	T length_squared() const { return x * x + y * y; }

  public:
	T x, y;
};

template <typename T>
std::ostream &operator<<(std::ostream &out, const _vec2<T> &v) {
	return out << v.x << " " << v.y;
}

template <typename T> std::istream &operator>>(std::istream &in, _vec2<T> &v) {
	return in >> v.x >> v.y;
}

template <typename T> T dot(_vec2<T> &u, _vec2<T> &v) {
	return u.x * v.x + u.y * v.y;
}

using vec2ui = _vec2<unsigned int>;
using vec2i = _vec2<int>;
using vec2f = _vec2<float>;
using vec2 = _vec2<float>;
using vec2d = _vec2<double>;
} // namespace oglm
