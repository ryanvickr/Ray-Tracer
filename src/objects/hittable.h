#ifndef HITTABLE_H
#define HITTABLE_H

#include "../math/ray.h"
#include "../math/vec3.h"

namespace object {

struct HitRecord {
  Point3 p;
  Vec3 normal;
  double t;
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
