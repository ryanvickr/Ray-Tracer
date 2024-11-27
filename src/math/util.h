#ifndef MATH_UTIL_H
#define MATH_UTIL_H

#include <limits>

namespace math_utils {

// Constants

static const double INF = std::numeric_limits<double>::infinity();
static const double PI = 3.1415926535897932385;

// Utility Functions

inline double degrees_to_radians(const double degrees) {
  return degrees * PI / 180.0;
}

}  // namespace math_util

#endif  // MATH_UTIL_H
