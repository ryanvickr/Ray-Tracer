cmake_minimum_required(VERSION 3.5.0)
project(RayTracer VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 23)

set ( SOURCES
  src/main.cc
  src/math/interval.h
  src/math/interval.cc
  src/math/ray.h
  src/math/ray.cc
  src/math/util.h
  src/math/vec3.h
  src/math/vec3.cc
  src/objects/hittable.h
  src/objects/hittable.cc
  src/objects/hittable-list.h
  src/objects/hittable-list.cc
  src/objects/sphere.h
  src/objects/sphere.cc
  src/rendering/camera.h
  src/rendering/camera.cc
)

message (STATUS "Compiler ID: " ${CMAKE_CXX_COMPILER_ID})
message (STATUS "Release flags: " ${CMAKE_CXX_FLAGS_RELEASE})
message (STATUS "Debug flags: " ${CMAKE_CXX_FLAGS_DEBUG})

add_executable(RayTracer ${SOURCES})
