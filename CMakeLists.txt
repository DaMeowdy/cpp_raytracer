cmake_minimum_required(VERSION 3.20)
project(CSE3PSD_Assignment_3_21985164)

set(CMAKE_CXX_STANDARD 23)

add_executable(CSE3PSD_Assignment_3_21985164
    "include/camera.h"
    "include/colour3.h"
    "include/helper_functions.h"
    "include/interval.h"
    "include/ray.h"
    "include/object.h"
    "include/sphere.h"
    "include/scene.h"
    "include/vec3.h"
    "include/renderer.h"
    "include/renderer_parameters.h"
    "include/progress_bar.h"
    "lib/camera.cpp"
    "lib/colour3.cpp"
    "lib/helper_functions.cpp"
    "lib/interval.cpp"
    "lib/ray.cpp"
    "lib/scene.cpp"
    "lib/vec3.cpp"
    "lib/renderer.cpp"
    "lib/renderer_parameters.cpp"
    "lib/progress_bar.cpp"
    "lib/sphere.cpp"
    "main.cpp"
)


