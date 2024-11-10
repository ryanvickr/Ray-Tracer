// Created by: Ryan Vickramasinghe

#include <iostream>

#include "math/vec3.h"

int main(int, char**) {
  // Image

  int image_width = 256;
  int image_height = 256;

  // Render

  std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

  for (int j = 0; j < image_height; j++) {
    std::clog << "\rScanlines remaining: " << (image_height - j) << ' '
              << std::flush;
    for (int i = 0; i < image_width; i++) {
      const double r = double(i) / (image_width - 1);
      const double g = double(j) / (image_height - 1);
      const double b = 0.0;

      auto pixel_color = Color(r, g, b);
      std::cout << pixel_color;
    }
  }

  std::clog << "\rDone.\n";
}
