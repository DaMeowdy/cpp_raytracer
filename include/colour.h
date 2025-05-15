#ifndef CSE3PSD_ASSIGNMENT_3_RAYTRACER_COLOUR_H
#define CSE3PSD_ASSIGNMENT_3_RAYTRACER_COLOUR_H

#include <ostream>
#include "vec3.h"
void WriteColour(std::ostream &out, Colour3 inPixelColour);
Colour3 GetColour(const Vec3& inputVector);
#endif
