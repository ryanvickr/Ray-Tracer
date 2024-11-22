#include "sphere.h"

#include "../math/ray.h"
#include "../math/vec3.h"

const Point3& Sphere::centroid() const { return centroid_; }

double Sphere::radius() const { return radius_; }

double Sphere::distanceFromSphere(const Ray& r) const {
  const Vec3 oc = centroid_ - r.origin();

  // A vector dotted by itself is equal to the squared length
  // of that vector.
  const double a = r.direction().length_squared();
  // This allows us to simplify calculation of the discriminant.
  const double h = r.direction().dot(oc);
  const double c = oc.length_squared() - std::pow(radius_, 2);

  // We only care that the discriminant is valid; this
  // tells us that this ray intersects with the sphere
  // at some point.
  const double discriminant = h * h - a * c;

  if (discriminant < 0) {
    // This ray doesn't intersect with this sphere.
    return -1;
  } else {
    return (h - std::sqrt(discriminant)) / (2.0 * a);
  }
}
