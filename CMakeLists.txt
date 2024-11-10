cmake_minimum_required(VERSION 3.5.0)
project(RayTracer VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 20)

set ( SOURCES
  src/main.cc
  src/math/vec3.h
  src/math/vec3.cc
  src/util/color.h
)

add_executable(RayTracer ${SOURCES})
