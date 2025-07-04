#ifndef CSE3PSD_ASSIGNMENT_3_RAYTRACER_OBJECT_H
#define CSE3PSD_ASSIGNMENT_3_RAYTRACER_OBJECT_H
#include "hit_record.h"
#include "ray.h"
#include "interval.h"
#include "material.h"
#include "aabb.h"
class Object 
{
  public: 
  virtual bool Hit(const Ray& ray, Interval ray_t ,HitRecord& rec) const =0;
  virtual bool BoundingBox(AABB& output_box) const = 0;
};
#endif
