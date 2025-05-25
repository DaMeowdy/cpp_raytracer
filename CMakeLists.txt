cmake_minimum_required(VERSION 3.20)
project(CSE3PSD_Assignment_3_21985164)

set(CMAKE_CXX_STANDARD 23)
add_executable(CSE3PSD_Assignment_3_21985164
    "include/ray.h"
    "include/vec3.h"
    "include/image.h"
    "include/plane.h"
    "include/scene.h"
    "include/colour.h"
    "include/camera.h"
    "include/sphere.h"
    "include/glossy.h"
    "include/object.h"
    "include/interval.h"
    "include/renderer.h"
    "include/material.h"
    "include/hit_record.h"
    "include/reflective.h"
    "include/progress_bar.h"
    "include/pure_diffuse.h"
    "include/helper_functions.h"
    "include/rendering_engine_includes.h"
    "lib/ray.cpp"
    "lib/vec3.cpp"
    "lib/scene.cpp"
    "lib/plane.cpp"
    "lib/image.cpp"
    "lib/glossy.cpp"
    "lib/sphere.cpp"
    "lib/camera.cpp"
    "lib/colour.cpp"
    "lib/renderer.cpp"
    "lib/interval.cpp"
    "lib/reflective.cpp"
    "lib/progress_bar.cpp"
    "lib/pure_diffuse.cpp"
    "lib/helper_functions.cpp"
    "main.cpp"
)


