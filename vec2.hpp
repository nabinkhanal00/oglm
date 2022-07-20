#pragma once

#include <cmath>
#include <iostream>

namespace oglm {

template <typename T = float> class vec2 {
  public:
	vec2() : x(0), y(0) {}

	vec2(T e0, T e1) : x(e0), y(e1) {}

	vec2 operator-() const { return vec2(-x, -y); }

	vec2 &operator-=(const vec2 &v) {
		x += v.x;
		y += v.y;
		return *this;
	}

  T & operator[](const int &i){
    if(i == 0)
      return x;
    if(i == 1)
      return y;
    throw "Index out of range";
  }
	vec2 &operator+=(const vec2 &v) {
		x += v.x;
		y += v.y;
		return *this;
	}

	vec2 &operator*=(const float &t) {
		x *= t;
		y *= t;
		return *this;
	}

	vec2 &operator/=(const float &t) {
		x /= t;
		y /= t;
		return *this;
	}

	vec2 operator+(const vec2 &v) { return vec2(x + v.x, y + v.y); }

	vec2 operator-(const vec2 &v) { return vec2(x - v.x, y - v.y); }

	vec2 operator*(const float &t) { return vec2(t * x, t * y); }

	friend vec2 operator*(const float &t, const vec2 &v) {
		return vec2(t * v.x, t * v.y);
	}

	vec2 operator/(const float &t) { return vec2(t / x, t / y); }

	vec2 unit() { return vec2<T>(x, y) / length(); }

	T length() const { return std::sqrt(length_squared()); }

	T dot(const vec2 &v) { return x * v.x + y * v.y; }

	T length_squared() const { return x * x + y * y; }

  public:
	T x, y;
};

template <typename T>
std::ostream &operator<<(std::ostream &out, const vec2<T> &v) {
	return out << v.x << " " << v.y;
}

template <typename T> std::istream &operator>>(std::istream &in, vec2<T> &v) {
	return in >> v.x >> v.y;
}

template <typename T> T dot(vec2<T> &u, vec2<T> &v) {
	return u.x * v.x + u.y * v.y;
}

using vec2i = vec2<int>;
using vec2f = vec2<float>;
} // namespace oglm
