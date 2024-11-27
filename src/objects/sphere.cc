#include "sphere.h"

#include <optional>

#include "../math/interval.h"
#include "../math/ray.h"
#include "../math/vec3.h"

namespace object {

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
    return (h - std::sqrt(discriminant)) / a;
  }
}

std::optional<HitRecord> Sphere::get_hit(const Ray& ray,
                                         const Interval& ray_t_bounds) const {
  const Vec3 oc = centroid_ - ray.origin();

  // A vector dotted by itself is equal to the squared length
  // of that vector.
  const double a = ray.direction().length_squared();
  // This allows us to simplify calculation of the discriminant.
  const double h = ray.direction().dot(oc);
  const double c = oc.length_squared() - std::pow(radius_, 2);

  // We only care that the discriminant is valid; this
  // tells us that this ray intersects with the sphere
  // at some point.
  const double discriminant = h * h - a * c;
  if (discriminant < 0) return std::nullopt;

  const double sqrtd = std::sqrt(discriminant);

  // Now find the nearest root within the allowable range. This is the
  // simplified quadratic equation for a sphere.
  double root = (h - sqrtd) / a;
  if (!ray_t_bounds.surrounds(root)) {
    // Try the other root if this is invalid.
    root = (h + sqrtd) / a;
    if (!ray_t_bounds.surrounds(root)) return std::nullopt;
  }

  // We have a valid hit point, create the `HitRecord` object and return it.
  Point3 p = ray.at(root);
  Vec3 normal = (p - centroid_) / radius_;
  HitRecord rec{
      .t = std::move(root),
      .p = std::move(p),
  };
  rec.set_face_normal(ray, std::move(normal));

  return rec;
}

}  // namespace object
