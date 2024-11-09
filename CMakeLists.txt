cmake_minimum_required(VERSION 3.5.0)
project(RayTracer VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 20)

add_library(Vec3 math/vec3.h math/vec3.cc)

add_executable(RayTracer main.cpp)
target_link_libraries(RayTracer PRIVATE Vec3)
