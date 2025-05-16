#ifndef CSE3PSD_ASSIGNMENT_3_RAYTRACER_HIT_RECORD_H
#define CSE3PSD_ASSIGNMENT_3_RAYTRACER_HIT_RECORD_H
#include "vec3.h"
struct HitRecord 
{
  Point3 p;
  Vec3 normal; 
  double t;
};



#endif
