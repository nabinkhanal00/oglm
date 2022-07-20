#include "oglm.hpp"
namespace oglm {
template <typename T>
mat4<T> lookAt(const vec3<T>& eye, const vec3<T>& towards, const vec3<T>& up) {
    vec3<T> forwardDir = normalize(towards - eye);
    vec3<T> rightDir = cross(forwardDir, normalize(up));
    vec3<T> upDir = cross(rightDir, forwardDir);

    mat4<T> result;
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

template <typename T> mat4<T> perspective(T fov, T aspect, T near, T far) {
    mat4<T> result(1);
    T const rad = fov;
    T const tanHalfFov = tan(rad / static_cast<T>(2)); // tanHalfFov == theta/2
    result[0][0] = static_cast<T>(1) / (aspect * tanHalfFov);
    result[1][1] = static_cast<T>(1) / (tanHalfFov);
    result[2][2] = -(far + near) / (far - near);
    result[2][3] = -static_cast<T>(1);
    result[3][2] = -(static_cast<T>(2) * far * near) / (far - near);
    return result;
}

template <typename T> mat4<T> translate(const vec3<T> tVec) {
    mat4<T> translateMat;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j)
                translateMat[i][j] == 1;
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

template <typename T> mat3<T> translate(const vec2<T>& tVec) {
    mat3<T> translateMat;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j)
                translateMat.arr[i][j] == 1;
            else {
                if (j == 2 && i < 2)
                    translateMat[i][j] = tVec[i];
                else
                    translateMat.arr[i][j] = 0;
            }
        }
    }
    return translateMat;
}
template <typename T> mat4<T> scale(const vec3<T>& sVec) {
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
template <typename T> mat3<T> scale(const vec2<T>& sVec) {
    mat3<T> scaleMat;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j)
                if (i < 2)
                    scaleMat.arr[i][j] == sVec[i];
                else
                    scaleMat.arr[i][j] == 1;
            else
                scaleMat.arr[i][j] = 0;
        }
    }
    return scaleMat;
}
template <typename T> mat4<T> rotate(float theta, const vec3<T>& axesVec) {
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
template <typename T> mat3<T> rotate(float theta, const vec2<T>& axesVec) {
    mat3<T> rotMat;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j)
                rotMat.arr[i][j] == 1;
            else
                rotMat.arr[i][j] = 0;
        }
    }
    theta = theta * (M_PI / 180);
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
 
