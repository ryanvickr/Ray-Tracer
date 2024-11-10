#include "ray.h"

#include "vec3.h"

const Point3& Ray::origin() const { return origin_; }

const Vec3& Ray::direction() const { return direction_; }

Point3 Ray::at(const double t) const {return origin_ + direction_ * t; }
