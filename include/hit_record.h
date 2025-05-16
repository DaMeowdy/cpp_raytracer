#ifndef CSE3PSD_ASSIGNMENT_3_RAYTRACER_HIT_RECORD_H
#define CSE3PSD_ASSIGNMENT_3_RAYTRACER_HIT_RECORD_H
#include "vec3.h"
#include "ray.h"
class HitRecord 
{
  public:
    Point3 p;
    Vec3 normal; 
    double t;
    Colour3 attenuation;
    Ray scattered;
    Vec3 direction;
};



#endif
