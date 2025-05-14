#ifndef CSE3PSD_ASSIGNMENT3_OBJECT_H
#define CSE3PSD_ASSIGNMENT3_OBJECT_H
#include "hit_record.h"
#include "colour3.h"
#include "ray.h"
#include "interval.h"
class Object
{
  public:
  virtual std::optional<HitRecord> RayHit(const Ray& ray, Interval rayInterval) const = 0;
  virtual Colour3 RayColour(const Ray& ray) =0;
};

#endif
