#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include <memory>

#include "hittable.h"

namespace object {

class HittableList : public Hittable {
 public:
  HittableList() = default;

  HittableList(std::unique_ptr<Hittable> object);

  void clear();

  void add(std::unique_ptr<Hittable> object);

  /// @brief Returns a HitRecord for the first object that the passed in `Ray`
  /// collides with.
  /// @param ray the `Ray` we want to get a collision for
  /// @param ray_tmin the minimum distance at which we can have a collision
  /// @param ray_tmax the maximum distanc at which we can have a collision
  /// @return returns a `HitRecord` for the first object hit. Returns
  /// `std::nullopt` if there were no collisions
  std::optional<HitRecord> get_hit(const Ray& ray, const double ray_tmin,
                                   const double ray_tmax) const override;

 private:
  std::vector<std::unique_ptr<Hittable>> objects_;
};

}  // namespace object

#endif  // HITTABLE_LIST_H
