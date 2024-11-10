#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class Ray {
 public:
  Ray() {}

  Ray(const Point3& origin, const Vec3& direction)
      : origin_(origin), direction_(direction) {}

  const Point3& origin() const;

  const Vec3& direction() const;

  Point3 at(const double t) const;

 private:
  const Point3 origin_;
  const Vec3 direction_;
};

#endif  // RAY_H