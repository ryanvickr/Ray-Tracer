#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <vector>
#include <utility>

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

  Vec3 unit_vector() const;

  Vec3 operator-() const;

  Vec3 operator-(const Vec3& v) const;

  Vec3 operator+(const Vec3& v) const;

  Vec3 operator+=(const Vec3& v);

  Vec3 operator*(const double scalar) const;

  Vec3 operator*(const Vec3& v) const;

  Vec3 operator*=(const Vec3& v);

  Vec3 operator/(const double scalar) const;

  Vec3 operator/=(const Vec3& v);

 private:
  // Stores the elements in this vector.
  std::vector<double> e_;
};

inline std::ostream& operator<<(std::ostream& out, const Vec3& v) {
  return out << v.x() << ' ' << v.y() << ' ' << v.z();
}

inline Vec3 operator*(const double scalar, const Vec3& v) { return v * scalar; }

// Helps distinguish points from actual vectors.
using Point3 = Vec3;

class Color : public Vec3 {
 public:
  Color() : Vec3() {}

  Color(const double& red, const double& green, const double& blue)
      : Vec3(red, green, blue) {}

  Color(Vec3&& v) : Vec3(std::move(v)) {}
};

inline std::ostream& operator<<(std::ostream& out, const Color& color) {
  auto r = color.x();
  auto g = color.y();
  auto b = color.z();

  // Translate the [0,1] component values to the byte range [0,255].
  int rbyte = int(255.999 * r);
  int gbyte = int(255.999 * g);
  int bbyte = int(255.999 * b);

  // Write out the pixel color components.
  return out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

#endif  // VEC3_H