cmake_minimum_required(VERSION 3.20)
project(CSE3PSD_Assignment_3_21985164)

set(CMAKE_CXX_STANDARD 23)

add_executable(CSE3PSD_Assignment_3_21985164
    "include/vec3.h"
    "include/renderer.h"
    "include/image.h"
    "include/colour.h"
    "include/helper_functions.h"
    "include/camera.h"
    "include/sphere.h"
    "include/ray.h"
    "include/scene.h"
    "include/object.h"
    "include/interval.h"
    "include/hit_record.h"
    "include/reflective.h"
    "include/pure_diffuse.h"
    "include/material.h"
    "include/plane.h"
    "lib/ray.cpp"
    "lib/plane.cpp"
    "lib/pure_diffuse.cpp"
    "lib/reflective.cpp"
    "lib/interval.cpp"
    "lib/vec3.cpp"
    "lib/sphere.cpp"
    "lib/scene.cpp"
    "lib/camera.cpp"
    "lib/renderer.cpp"
    "lib/image.cpp"
    "lib/colour.cpp"
    "lib/helper_functions.cpp"
    "main.cpp"
)


