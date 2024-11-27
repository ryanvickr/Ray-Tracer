#ifndef RENDERING_CAMERA_H
#define RENDERING_CAMERA_H

#include "../math/vec3.h"
#include "../objects/hittable-list.h"

namespace renderer {

class Camera {
 public:
  Camera();

  Camera(const double aspect_ratio, const int image_width);

  void render(const object::Hittable& world);

 private:
  const double aspect_ratio_;  // Ratio of image width over height
  const int image_width_;      // Rendered image width in pixel count
  int image_height_;           // Rendered image height
  Point3 center_;              // Camera center
  Point3 pixel00_loc_;         // Location of pixel 0, 0
  Vec3 pixel_delta_u_;         // Offset to pixel to the right
  Vec3 pixel_delta_v_;         // Offset to pixel below

  void initialize();

  Color ray_color(const Ray& r, const object::Hittable& world);
};

}  // namespace renderer

#endif  // RENDERING_CAMERA_H
