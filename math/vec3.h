#ifndef VEC3_H
#define VEC3_H

#include <vector>

class Vec3 {
 public:
  Vec3() : e{0, 0, 0} {}

  Vec3(const double& e0, const double& e1, const double& e2) : e{e0, e1, e2} {}

  double x();

  double y();

  double z();

  double length() const;

  double length_squared() const;

  Vec3 operator-() const { return Vec3(-e[0], -e[1], -e[2]); }

  Vec3 operator+=(const Vec3& v) {
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];
    return *this;
  }

  Vec3 operator*=(const Vec3& v) {
    e[0] *= v.e[0];
    e[1] *= v.e[1];
    e[2] *= v.e[2];
    return *this;
  }

  Vec3 operator/=(const Vec3& v) {
    e[0] /= v.e[0];
    e[1] /= v.e[1];
    e[2] /= v.e[2];
    return *this;
  }

 private:
  // Stores the elements in this vector.
  std::vector<double> e;
};

#endif  // VEC3_H