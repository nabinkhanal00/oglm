#pragma once
#include "vec4.hpp"
#include "vec3.hpp"
#include "vec2.hpp"
#include "mat4.hpp"
#include "mat3.hpp"

namespace oglm {
template <typename T>
_mat4<T> lookAt(const _vec3<T> &eye, const _vec3<T> &towards,
                const _vec3<T> &up) {
	_vec3<T> forwardDir = normalize(towards - eye);
	_vec3<T> rightDir = cross(forwardDir, normalize(up));
	_vec3<T> upDir = cross(rightDir, forwardDir);

	_mat4<T> result;
	result[0][0] = rightDir.x;
	result[1][0] = rightDir.y;
	result[2][0] = rightDir.z;
	result[3][0] = -dot(rightDir, eye);

	result[0][1] = upDir.x;
	result[1][1] = upDir.y;
	result[2][1] = upDir.z;
	result[3][1] = -dot(upDir, eye);

	result[0][2] = -forwardDir.x;
	result[1][2] = -forwardDir.y;
	result[2][2] = -forwardDir.z;
	result[3][2] = dot(forwardDir, eye);

	result[0][3] = 0;
	result[1][3] = 0;
	result[2][3] = 0;
	result[3][3] = 1;

	return result;
}

template <typename T> _mat4<T> perspective(T fov, T aspect, T near, T far) {
	_mat4<T> result(1);
	T const rad = fov;
	T const tanHalfFov = tan(rad / static_cast<T>(2)); // tanHalfFov == theta/2
	result[0][0] = static_cast<T>(1) / (aspect * tanHalfFov);
	result[1][1] = static_cast<T>(1) / (tanHalfFov);
	result[2][2] = -(far + near) / (far - near);
	result[3][3] = 0;
	result[3][2] = -static_cast<T>(1);
	result[2][3] = -(static_cast<T>(2) * far * near) / (far - near);
	return result;
}

template <typename T> _mat4<T> translate(const _vec3<T> tVec) {
	_mat4<T> translateMat;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j)
				translateMat[i][j] = 1;
			else {
				if (j == 3 && i < 3)

					translateMat[i][j] = tVec[i];
				else
					translateMat[i][j] = 0;
			}
		}
	}
	return translateMat;
}

template <typename T> _mat3<T> translate(const _vec2<T> &tVec) {
	_mat3<T> translateMat;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j)
				translateMat[i][j] = 1;
			else {
				if (j == 2 && i < 2)
					translateMat[i][j] = tVec[i];
				else
					translateMat[i][j] = 0;
			}
		}
	}
	return translateMat;
}
template <typename T> _mat4<T> scale(const _vec3<T> &sVec) {
	_mat4<T> scaleMat;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j)
				if (i < 3)
					scaleMat[i][j] = sVec[i];
				else
					scaleMat[i][j] = 1;
			else
				scaleMat[i][j] = 0;
		}
	}
	return scaleMat;
}
template <typename T> _mat3<T> scale(const _vec2<T> &sVec) {
	_mat3<T> scaleMat;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j)
				if (i < 2)
					scaleMat[i][j] = sVec[i];
				else
					scaleMat[i][j] = 1;
			else
				scaleMat[i][j] = 0;
		}
	}
	return scaleMat;
}
template <typename T>
_mat4<T> rotate(const float &theta, const _vec3<T> &axesVec) {
	axesVec = oglm::normalize(axesVec);
	_mat4<T> rotMat;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j)
				rotMat[i][j] = 1;
			else
				rotMat[i][j] = 0;
		}
	}
	T x = axesVec[0];
	T y = axesVec[1];
	T z = axesVec[2];
	float s = sin(theta);
	float c = cos(theta);
	float omc = 1 - cos(theta);
	rotMat[0][0] = c + x * x * omc;
	rotMat[0][1] = x * y * omc - z * s;
	rotMat[0][2] = x * y * omc + y * s;
	rotMat[1][0] = y * x * omc + z * s;
	rotMat[1][1] = c + y * y * omc;
	rotMat[1][2] = y * z * omc - x * s;
	rotMat[2][0] = z * x * omc - y * s;
	rotMat[2][1] = z * y * omc + x * s;
	rotMat[2][2] = c + z * z * omc;
	return rotMat;
}
template <typename T>
_mat3<T> rotate(const float &theta, const _vec2<T> &axesVec) {
	axesVec = oglm::normalize(axesVec);
	_mat3<T> rotMat;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j)
				rotMat[i][j] = 1;
			else
				rotMat[i][j] = 0;
		}
	}
	T x = axesVec[0];
	T y = axesVec[1];
	float s = sin(theta);
	float c = cos(theta);
	float omc = 1 - cos(theta);
	rotMat[0][0] = c;
	rotMat[0][1] = -s;
	rotMat[0][2] = x * omc + y * s;
	rotMat[1][0] = s;
	rotMat[1][1] = c;
	rotMat[1][2] = y * omc - x * s;
	return rotMat;
}
} // namespace oglm
