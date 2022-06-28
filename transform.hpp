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

template <typename T> mat4<T> translate(const vec3<T> &tVec) {
  mat4<T> translateMat;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i == j)
        translateMat.arr[i][j] == 1;
      else {
        if (j == 3 && i < 3)
          translateMat[i][j] = tVec[i];
        else
          translateMat.arr[i][j] = 0;
      }
    }
  }
  return translateMat;
}

template <typename T> mat4<T> scale(const vec3<T> &sVec) {
  mat4<T> scaleMat;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i == j)
        if (i < 3)
          scaleMat.arr[i][j] == sVec[i];
        else
          scaleMat.arr[i][j] == 1;
      else
        scaleMat.arr[i][j] = 0;
    }
  }
  return scaleMat;
}
template <typename T> mat4<T> rotate(float theta, const vec3<T> &axesVec) {
  mat4<T> rotMat;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i == j)
        rotMat.arr[i][j] == 1;
      else
        rotMat.arr[i][j] = 0;
    }
  }
  theta = theta * (M_PI / 180);
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
} // namespace oglm
