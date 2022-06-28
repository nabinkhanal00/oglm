#pragma once

#include <cmath>
#include <iostream>

namespace oglm {

template <typename T> class vec2 {
  public:
	vec2() : arr(0, 0), x(arr[0]), y(arr[1]) {}

	vec2(T e0, T e1) : arr(e0, e1), x(arr[0]), y(arr[1]) {}

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

	T &operator[](const unsigned int &i) { return arr[i]; }

  public:
	T arr[2];
	T &x, y;
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
	vec3() : arr{0, 0, 0}, x(arr[0]), y(arr[1]), z(arr[2]) {}

	vec3(T e0, T e1, T e2) : arr{e0, e1, e2}, x(arr[0]), y(arr[1]), z(arr[2]) {}

	vec3(T e, const vec2<T> &v)
	    : arr(e, v.x, v.y), x(arr[0]), y(arr[1]), z(arr[2]) {}

	vec3(const vec2<T> &v, T e)
	    : arr(v.x, v.y, e), x(arr[0]), y(arr[1]), z(arr[2]) {}

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

	vec3 &operator*=(const float &t) {
		x *= t;
		y *= t;
		z *= t;
		return *this;
	}

	vec3 &operator/=(const float &t) {
		x /= t;
		y /= t;
		z /= t;
		return *this;
	}

	vec3 operator/(float t) { return vec3(x / t, y / t, z / t); }

	T length() const { return std::sqrt(length_squared()); }

	T dot(const vec3 &v) { return x * v.x + y * v.y + z * v.z; }

	T length_squared() const { return x * x + y * y + z * z; }

	T &operator[](const unsigned int &i) { return arr[i]; }

  public:
	T arr[3];
	T &x, &y, &z;
};

template <typename T>
static std::ostream &operator<<(std::ostream &out, const vec3<T> &v) {
	return out << v.x << " " << v.y << " " << v.z;
}
template <typename T>
static std::istream &operator>>(std::istream &in, vec3<T> &v) {
	return in >> v.x >> v.y >> v.z;
}
template <typename T>
static vec3<T> operator+(const vec3<T> &u, const vec3<T> &v) {
	return vec3<T>(u.x + v.x, u.y + v.y, u.z + v.z);
}
template <typename T>
static vec3<T> operator-(const vec3<T> &u, const vec3<T> &v) {
	return vec3<T>(u.x - v.x, u.y - v.y, u.z - v.z);
}
template <typename T> static vec3<T> operator*(const vec3<T> &u, float t) {
	return vec3<T>(t * u.x, t * u.y, t * u.z);
}
template <typename T>
static vec3<T> operator*(const float &t, const vec3<T> &v) {
	return vec3<T>(t * v.x, t * v.y, t * v.z);
}
template <typename T> static T dot(const vec3<T> &u, const vec3<T> &v) {
	return u.x * v.x + u.y * v.y + u.z * v.z;
}
template <typename T> static vec3<T> cross(const vec3<T> &u, const vec3<T> &v) {
	return vec3<T>(u.y * v.z - u.z * v.y, u.z * v.x - u.x * v.z,
	               u.x * v.y - u.y * v.z);
}
template <typename T> static vec3<T> normalize(const vec3<T> &u) {
	T oneOverLength = (T)1 / u.length();
	return oneOverLength * vec3<T>(u.x, u.y, u.z);
}

using vec2i = vec2<int>;
using vec2f = vec2<float>;

using vec3i = vec3<int>;
using vec3f = vec3<float>;

template <typename T> class mat4 {
  public:
	T arr[4][4];
};
template <typename T> class mat3 {
  public:
	T arr[3][3];
};
} // namespace oglm
