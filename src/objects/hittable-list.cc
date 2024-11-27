#include "hittable-list.h"

#include <memory>

#include "hittable.h"

namespace object {

HittableList::HittableList(std::unique_ptr<Hittable> object) {
  add(std::move(object));
}

void HittableList::clear() { objects_.clear(); }

void HittableList::add(std::unique_ptr<Hittable> object) {
  objects_.emplace_back(std::move(object));
}

std::optional<HitRecord> HittableList::get_hit(const Ray& ray,
                                               const double ray_tmin,
                                               const double ray_tmax) const {
  HitRecord rec;
  bool found_hit = false;
  double closest_t = ray_tmax;

  for (const auto& object : objects_) {
    auto hit_rec = object->get_hit(ray, ray_tmin, ray_tmax);
    if (!hit_rec.has_value()) continue;

    found_hit = true;
    closest_t = hit_rec->t;
    rec = std::move(*hit_rec);
  }

  if (!found_hit) return std::nullopt;
  return rec;
}

}  // namespace object
