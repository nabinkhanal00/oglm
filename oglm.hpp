#pragma once
#include "vec2.hpp"
#include "vec3.hpp"
namespace oglm{
template <typename T> class mat4 {
  public:
	T arr[4][4];
};
template <typename T> class mat3 {
  public:
	T arr[3][3];
};
}
