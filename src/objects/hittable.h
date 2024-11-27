#ifndef HITTABLE_H
#define HITTABLE_H

#include "../math/ray.h"
#include "../math/vec3.h"

namespace object {

struct HitRecord {
  Point3 p;
  Vec3 normal;
  double t;
  // Whether or not the hit was on the exterior (`true`) or interior (`false`).
  bool front_face;
  /// @brief Sets whether or not this contact was on the exterior or interior of
  /// the object.
  ///
  /// Iff exterior, `front_face == true`, else it is false. It also updates the
  /// `normal` so that is has the correct direction.
  /// @param r the `Ray` which made contact with this point
  /// @param outward_normal the surface normal unit vector (pointing outwards)
  void set_face_normal(const Ray& r, const Vec3& outward_normal);
};

// A pure virtual class for a hittable object.
//
// TODO: Use templating to speed this portion up (since virtual functions
// can be slow).
class Hittable {
 public:
  virtual ~Hittable() = default;

  virtual std::optional<HitRecord> get_hit(const Ray& ray,
                                           const double ray_tmin,
                                           const double ray_tmax) const = 0;
};

}  // namespace object

#endif  // HITTABLE_H
