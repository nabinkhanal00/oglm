#pragma once

#include <cmath>
#include <iostream>

namespace oglm {

template <typename T> class vec2 {
  public:
	vec2() : x(0), y(0) {}

	vec2(T e0, T e1) : x(e0), y(e1) {}

	vec2 operator-() const { return vec2(-x, -y); }

	vec2 &operator-=(const vec2 &v) {
		x += v.x;
		y += v.y;
		return *this;
	}

	vec2 &operator+=(const vec2 &v) {
		x += v.x;
		y += v.y;
		return *this;
	}

	vec2 &operator*=(const float t) {
		x *= t;
		y *= t;
		return *this;
	}

	vec2 &operator/=(const float t) {
		x /= t;
		y /= t;
		return *this;
	}

	vec2 operator+(const vec2 &v) { return vec2(x + v.x, y + v.y); }

	vec2 operator-(const vec2 &v) { return vec2(x - v.x, y - v.y); }

	vec2 operator*(float t) { return vec2(t * x, t * y); }

	friend vec2 operator*(float t, const vec2 &v) {
		return vec2(t * v.x, t * v.y);
	}

	vec2 operator/(float t) { return vec2(t / x, t / y); }

	vec2 unit() { return (*this) / length(); }

	T length() const { return std::sqrt(length_squared()); }

	T dot(vec2 &v) { return x * v.x + y * v.y; }

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

template <typename T> class vec3 {
  public:
	vec3() : x(0), y(0), z(0) {}

	vec3(T e0, T e1, T e2) : x(e0), y(e1), z(e2) {}

	vec3(T e, vec2<T> v) : x(e), y(v.x), z(v.y) {}

	vec3(vec2<T> v, T e) : x(v.x), y(v.y), z(e) {}

	vec3 operator-() const { return vec3(-x, -y, -z); }

	vec3 &operator+=(const vec3 &v) {
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}

	vec3 &operator-=(const vec3 &v) {
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}

	vec3 &operator*=(const float t) {
		x *= t;
		y *= t;
		z *= t;
		return *this;
	}

	vec3 &operator/=(const float t) {
		x /= t;
		y /= t;
		z /= t;
		return *this;
	}

	vec3 operator/(float t) { return vec3(x / t, y / t, z / t); }

	vec3 unit() { return (*this) / length(); }

	T length() const { return std::sqrt(length_squared()); }

	T dot(vec3 &v) { return x * v.x + y * v.y + z * v.z; }

	T length_squared() const { return x * x + y * y + z * z; }

  public:
	T x, y, z;
};
template <typename T>
std::ostream &operator<<(std::ostream &out, const vec3<T> &v) {
	return out << v.x << " " << v.y << " " << v.z;
}
template <typename T> std::istream &operator>>(std::istream &in, vec3<T> &v) {
	return in >> v.x >> v.y >> v.z;
}
template <typename T> vec3<T> operator+(const vec3<T> &u, const vec3<T> &v) {
	return vec3<T>(u.x + v.x, u.y + v.y, u.z + v.z);
}
template <typename T> vec3<T> operator-(const vec3<T> &u, const vec3<T> &v) {
	return vec3<T>(u.x - v.x, u.y - v.y, u.z - v.z);
}
template <typename T> vec3<T> operator*(const vec3<T> &u, float t) {
	return vec3<T>(t * u.x, t * u.y, t * u.z);
}
template <typename T> vec3<T> operator*(float t, const vec3<T> &v) {
	return vec3<T>(t * v.x, t * v.y, t * v.z);
}
template <typename T> T dot(const vec3<T> &u, const vec3<T> &v) {
	return u.x * v.x + u.y * v.y + u.z * v.z;
}
template <typename T> vec3<T> cross(vec3<T> &u, vec3<T> &v) {
	return vec3<T>(u.y * v.z - u.z * v.y, u.z * v.x - u.x * v.z,
	               u.x * v.y - u.y * v.z);
}
using vec2i = vec2<int>;
using vec2f = vec2<float>;

using vec3i = vec3<int>;
using vec3f = vec3<float>;
} // namespace oglm
