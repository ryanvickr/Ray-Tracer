#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <vector>

class Vec3 {
 public:
  Vec3() : e_{0, 0, 0} {}

  Vec3(const double& e0, const double& e1, const double& e2) : e_{e0, e1, e2} {}

  double x() const;

  double y() const;

  double z() const;

  double length() const;

  double length_squared() const;

  double dot(const Vec3& v) const;

  Vec3 cross(const Vec3& v);

  Vec3 unit_vector();

  Vec3 operator-() const;

  Vec3 operator-(const Vec3& v);

  Vec3 operator+(const Vec3& v);

  Vec3 operator+=(const Vec3& v);

  Vec3 operator*(const double scalar);

  Vec3 operator*(const Vec3& v);

  Vec3 operator*=(const Vec3& v);

  Vec3 operator/(const double scalar);

  Vec3 operator/=(const Vec3& v);

  std::ostream& operator<<(std::ostream& out);

 private:
  // Stores the elements in this vector.
  std::vector<double> e_;
};

#endif  // VEC3_H