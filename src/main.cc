// Created by: Ryan Vickramasinghe

#include <iostream>
#include <memory>

#include "math/ray.h"
#include "objects/hittable-list.h"
#include "objects/sphere.h"
#include "rendering/camera.h"

int main(int, char**) {
  object::HittableList world;
  world.add(std::make_unique<object::Sphere>(Point3(0, 0, -1), 0.5));
  world.add(std::make_unique<object::Sphere>(Point3(0, -100.5, -1), 100));

  double aspect_ratio = 16.0 / 9.0;
  int image_width = 400;
  renderer::Camera cam(aspect_ratio, image_width);

  cam.render(world);
}
