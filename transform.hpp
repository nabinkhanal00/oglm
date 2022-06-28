#include "oglm.hpp"

namespace oglm {
template <typename T>
mat4<T> lookAt(const vec3<T> &eye, const vec3<T> &towards, const vec3<T> &up) {
	vec3<T> forwardDir = normalize(towards - eye);
	vec3<T> rightDir = cross(forwardDir, normalize(up));
	vec3<T> upDir = cross(rightDir, forwardDir);

	mat4<T> result;
	result.arr[0][0] = rightDir.x;
	result.arr[1][0] = rightDir.y;
	result.arr[2][0] = rightDir.z;
	result.arr[3][0] = -dot(rightDir, eye);

	result.arr[0][1] = upDir.x;
	result.arr[1][1] = upDir.y;
	result.arr[2][1] = upDir.z;
	result.arr[3][1] = -dot(upDir, eye);

	result.arr[0][2] = -forwardDir.x;
	result.arr[1][2] = -forwardDir.y;
	result.arr[2][2] = -forwardDir.z;
	result.arr[3][2] = dot(forwardDir, eye);

	result.arr[0][3] = 0;
	result.arr[1][3] = 0;
	result.arr[2][3] = 0;
	result.arr[3][3] = 1;

	return result;
}
} // namespace oglm
