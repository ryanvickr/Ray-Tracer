#include "sphere.h"

#include "../math/ray.h"
#include "../math/vec3.h"

const Point3& Sphere::centroid() const { return centroid_; }

double Sphere::radius() const { return radius_; }

bool Sphere::collidesWithRay(const Ray& r) const {
  const Vec3 oc = centroid_ - r.origin();

  const double a = r.direction().dot(r.direction());
  const double b = (-2 * r.direction()).dot(oc);
  const double c = oc.dot(oc) - std::pow(radius_, 2);

  // We only care that the discriminant is valid; this
  // tells us that this ray intersects with the sphere
  // at some point.
  const double discriminant = b * b - 4 * a * c;
  return discriminant >= 0;
}
