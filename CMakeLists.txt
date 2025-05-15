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
    "lib/vec3.cpp"
    "lib/camera.cpp"
    "lib/renderer.cpp"
    "lib/image.cpp"
    "lib/colour.cpp"
    "lib/helper_functions.cpp"
    "main.cpp"
)


