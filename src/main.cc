// Created by: Ryan Vickramasinghe

#include <iostream>

#include "math/ray.h"
#include "math/vec3.h"

Color ray_color(const Ray& r) {
  const Vec3 unit_direction = r.direction().unit_vector();
  double a = (unit_direction.y() + 1.0) * 0.5;
  Color test = Color(1.0, 1.0, 0) + Color(0,0,0);
  return (1.0-a)*Color(1.0, 1.0, 1.0) + a*Color(0.5, 0.7, 1.0);
}

int main(int, char**) {
  // Image
  const double aspect_ratio = 16.0 / 9.0;
  const int image_width = 400;

  // Calculate image height from the ratio, ensuring it is at least 1 pixel.
  const int image_height = std::max(int(image_width / aspect_ratio), 1);

  // Camera
  const double focal_length = 1.0;  // distance from camera center to viewport.
  const double viewport_height = 2.0;
  const double viewport_width =
      viewport_height * (double(image_width) / image_height);
  const auto camera_center = Point3(0, 0, 0);

  // Calculate vectors across the horizontal, and down the vertical viewport
  // edges.
  const auto viewport_u = Vec3(viewport_width, 0, 0);
  const auto viewport_v = Vec3(0, -viewport_height, 0);

  // Calculate the unit vectors for the viewport edges
  const auto unit_vec_u = viewport_u / image_width;
  const auto unit_vec_v = viewport_v / image_height;

  // Calculate the location of the upper left pixel.
  Point3 viewport_upper_left = camera_center - Vec3(0, 0, focal_length) -
                               viewport_u / 2 - viewport_v / 2;
  Point3 pixel00_loc = viewport_upper_left + (unit_vec_u + unit_vec_v) * 0.5;

  // Render

  std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

  for (int j = 0; j < image_height; j++) {
    std::clog << "\rScanlines remaining: " << (image_height - j) << ' '
              << std::flush;
    for (int i = 0; i < image_width; i++) {
      const auto pixel_center = pixel00_loc + (unit_vec_u * i) + (unit_vec_v * j);
      const auto ray_direction = pixel_center - camera_center;
      Ray r(camera_center, ray_direction);
      Color pixel_color = ray_color(r);
      std::cout << pixel_color;
    }
  }

  std::clog << "\rDone.\n";
}
