#ifndef SPHERE_H
#define SPHERE_H

#include "../math/ray.h"
#include "../math/vec3.h"

class Sphere {
 public:
  Sphere(const Point3& centroid, const double radius)
      : centroid_(centroid), radius_(radius) {}

  const Point3& centroid() const;

  double radius() const;

  // This function checks whether the ray collides with the sphere,
  // and if so, it returns the t value which is the distance. If
  // not, then it will return -1.0 (invalid, aka does not intersect).
  //
  // Uses a more efficient calculation of the quadratic formula.
  double distanceFromSphere(const Ray& r) const;

 private:
  const Point3 centroid_;
  const double radius_;
};

#endif  // SPHERE_H