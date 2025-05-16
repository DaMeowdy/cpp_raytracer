#ifndef CSE3PSD_ASSIGNMENT_3_RAYTRACER_COLOUR_H
#define CSE3PSD_ASSIGNMENT_3_RAYTRACER_COLOUR_H
#include "ray.h"
#include <ostream>
#include "vec3.h"
#include "scene.h"
void WriteColour(std::ostream &out, Colour3 inPixelColour);
Colour3 RayColour(const Ray& ray, const Scene& scene);
#endif
