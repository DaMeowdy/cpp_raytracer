#ifndef CSE3PSD_ASSIGNMENT_3_RAYTRACER_OBJECT_H
#define CSE3PSD_ASSIGNMENT_3_RAYTRACER_OBJECT_H
#include "hit_record.h"
#include "ray.h"

class Object 
{
  public: 
  virtual bool Hit(const Ray& ray, double t_min,double t_max,HitRecord& rec) const =0;

};
#endif
