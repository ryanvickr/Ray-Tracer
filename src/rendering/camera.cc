#include "camera.h"

#include "../math/ray.h"
#include "../math/util.h"

namespace renderer {

Camera::Camera() : aspect_ratio_(1.0), image_width_(100) {}

Camera::Camera(const double aspect_ratio, const int image_width)
    : aspect_ratio_(aspect_ratio), image_width_(image_width) {}

void Camera::render(const object::Hittable& world) {
  initialize();
  std::cout << "P3\n" << image_width_ << ' ' << image_height_ << "\n255\n";

  for (int j = 0; j < image_height_; j++) {
    std::clog << "\rScanlines remaining: " << (image_height_ - j) << ' '
              << std::flush;
    for (int i = 0; i < image_width_; i++) {
      auto pixel_center =
          pixel00_loc_ + (i * pixel_delta_u_) + (j * pixel_delta_v_);
      auto ray_direction = pixel_center - center_;
      Ray r(center_, ray_direction);

      Color pixel_color = ray_color(r, world);
      std::cout << pixel_color;
    }
  }

  std::clog << "\rDone.                 \n";
}

void Camera::initialize() {
  image_height_ = int(image_width_ / aspect_ratio_);
  image_height_ = (image_height_ < 1) ? 1 : image_height_;

  center_ = Point3(0, 0, 0);

  // Determine viewport dimensions.
  auto focal_length = 1.0;
  auto viewport_height = 2.0;
  auto viewport_width =
      viewport_height * (double(image_width_) / image_height_);

  // Calculate the vectors across the horizontal and down the vertical
  // viewport edges.
  auto viewport_u = Vec3(viewport_width, 0, 0);
  auto viewport_v = Vec3(0, -viewport_height, 0);

  // Calculate the horizontal and vertical delta vectors from pixel to pixel.
  pixel_delta_u_ = viewport_u / image_width_;
  pixel_delta_v_ = viewport_v / image_height_;

  // Calculate the location of the upper left pixel.
  auto viewport_upper_left =
      center_ - Vec3(0, 0, focal_length) - viewport_u / 2 - viewport_v / 2;
  pixel00_loc_ = viewport_upper_left + 0.5 * (pixel_delta_u_ + pixel_delta_v_);
}

Color Camera::ray_color(const Ray& r, const object::Hittable& world) {
  auto hit_record = world.get_hit(r, Interval(0, math_utils::INF));
  if (hit_record.has_value()) {
    return 0.5 * (hit_record->normal + Color(1, 1, 1));
  }

  const Vec3 unit_direction = r.direction().unit_vector();
  double a = (unit_direction.y() + 1.0) * 0.5;
  return (1.0 - a) * Color(1.0, 1.0, 1.0) + a * Color(0.5, 0.7, 1.0);
}

}  // namespace renderer
