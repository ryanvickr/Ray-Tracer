#include "hittable.h"

namespace object {

void HitRecord::set_face_normal(const Ray& r, const Vec3& outward_normal) {
  // A negative dot product means vectors are in opposite directions, meaning
  // that the ray comes from outside the object and make contact with the
  // exterior.
  front_face = r.direction().dot(outward_normal) < 0;
  // If the ray comes from the inside, the normal vector should point in the
  // opposite direction (inwards).
  normal = front_face ? outward_normal : -outward_normal;
}

}  // namespace object
