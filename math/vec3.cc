#include "vec3.h"

#include <cmath>

double Vec3::x() { return e[0]; }

double Vec3::y() { return e[1]; }

double Vec3::z() { return e[2]; }

double Vec3::length() const { return std::hypot(e[0], e[1], e[2]); }

double Vec3::length_squared() const {
  return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
}
