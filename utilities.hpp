#pragma once

#include <cmath>
namespace oglm {
inline const float radians(const float &degrees) {
	return M_PI / 180 * degrees;
}
inline const float degrees(const float &radians) {
	return 180 / M_PI * radians;
}
}; // namespace oglm
