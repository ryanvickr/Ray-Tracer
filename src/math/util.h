#ifndef UTIL_H
#define UTIL_H

#include <limits>

namespace util {

// Constants

static const double INFINITY = std::numeric_limits<double>::infinity();
static const double PI = 3.1415926535897932385;

// Utility Functions

inline double degrees_to_radians(const double degrees) {
  return degrees * PI / 180.0;
}

}  // namespace util

#endif  // UTIL_H