#include "vec3.h"
#ifndef CSE3PSD_ASSIGNMENT_3_RAYTRACER_MATERIAL_H
#define CSE3PSD_ASSIGNMENT_3_RAYTRACER_MATERIAL_H
#include "hit_record.h"
class Material
{
  public:
  virtual Vec3 ReflectLight(HitRecord& rec, Ray r = Ray()) const = 0;
};
#endif
