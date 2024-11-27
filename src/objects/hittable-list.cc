#include "hittable-list.h"

#include <memory>

#include "../math/interval.h"
#include "hittable.h"

namespace object {

HittableList::HittableList(std::unique_ptr<Hittable> object) {
  add(std::move(object));
}

void HittableList::clear() { objects_.clear(); }

void HittableList::add(std::unique_ptr<Hittable> object) {
  objects_.push_back(std::move(object));
}

std::optional<HitRecord> HittableList::get_hit(
    const Ray& ray, const Interval& ray_t_bounds) const {
  HitRecord rec;
  bool found_hit = false;
  double closest_t = ray_t_bounds.max();

  for (const auto& object : objects_) {
    auto hit_rec =
        object->get_hit(ray, Interval(ray_t_bounds.min(), closest_t));
    if (!hit_rec.has_value()) continue;

    found_hit = true;
    closest_t = hit_rec->t;
    rec = std::move(*hit_rec);
  }

  if (!found_hit) return std::nullopt;
  return rec;
}

}  // namespace object
