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

  bool collidesWithRay(const Ray& r) const;

 private:
  const Point3 centroid_;
  const double radius_;
};

#endif  // SPHERE_H