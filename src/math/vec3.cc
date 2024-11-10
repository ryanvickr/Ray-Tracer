#include "vec3.h"

#include <cmath>

double Vec3::x() const { return e_[0]; }

double Vec3::y() const { return e_[1]; }

double Vec3::z() const { return e_[2]; }

double Vec3::length() const { return std::hypot(e_[0], e_[1], e_[2]); }

double Vec3::length_squared() const {
  return e_[0] * e_[0] + e_[1] * e_[1] + e_[2] * e_[2];
}

double Vec3::dot(const Vec3& v) const {
  return e_[0] * v.e_[0] + e_[1] * v.e_[1] + e_[2] * v.e_[2];
}

// TODO: Look into using SIMD instructions for this.
Vec3 Vec3::cross(const Vec3& v) {
  return Vec3((e_[1] * v.e_[2] - e_[2] * v.e_[1]),
              (e_[2] * v.e_[0] * e_[0] * v.e_[2]),
              (e_[0] * v.e_[1] - e_[1] * v.e_[0]));
}

Vec3 Vec3::unit_vector() { return *this / length(); }

Vec3 Vec3::operator-() const { return Vec3(-e_[0], -e_[1], -e_[2]); }

Vec3 Vec3::operator-(const Vec3& v) {
  return Vec3(e_[0] - v.e_[0], e_[1] - v.e_[1], e_[2] - v.e_[2]);
}

Vec3 Vec3::operator+(const Vec3& v) {
  return Vec3(e_[0] + v.e_[0], e_[1] + v.e_[1], e_[2] + v.e_[2]);
}

Vec3 Vec3::operator+=(const Vec3& v) {
  e_[0] += v.e_[0];
  e_[1] += v.e_[1];
  e_[2] += v.e_[2];
  return *this;
}

Vec3 Vec3::operator*(const double scalar) {
  return Vec3(e_[0] * scalar, e_[1] * scalar, e_[2] * scalar);
}

Vec3 Vec3::operator*(const Vec3& v) {
  return Vec3(e_[0] * v.e_[0], e_[1] * v.e_[1], e_[2] * v.e_[2]);
}

Vec3 Vec3::operator*=(const Vec3& v) {
  e_[0] *= v.e_[0];
  e_[1] *= v.e_[1];
  e_[2] *= v.e_[2];
  return *this;
}

Vec3 Vec3::operator/(const double scalar) {
  return Vec3(e_[0] / scalar, e_[1] / scalar, e_[2] / scalar);
}

Vec3 Vec3::operator/=(const Vec3& v) {
  e_[0] /= v.e_[0];
  e_[1] /= v.e_[1];
  e_[2] /= v.e_[2];
  return *this;
}
