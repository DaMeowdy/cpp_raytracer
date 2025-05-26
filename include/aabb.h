#ifndef CSE3PSD_ASSIGNMENT_3_RAYTRACER_AABB_H
#define CSE3PSD_ASSIGNMENT_3_RAYTRACER_AABB_H
#include "interval.h"
#include "ray.h"
class AABB
{
  public: 
  AABB(){}
  AABB(const Interval& inX, const Interval& inY,const Interval& inZ):x_{inX},y_{inY},z_{inZ}{}
  AABB(const Point3& a, const Point3& b);
  Interval X() const;
  Interval Y() const;
  Interval Z() const;
  bool Hit(const Ray& ray, Interval t) const;
  Point3 Min() const;
  Point3 Max() const;
  static AABB SurroundingBox(const AABB& box_a, const AABB& box_b);
  private:
  Interval x_{empty_interval};
  Interval y_{empty_interval};
  Interval z_{empty_interval};
};

#endif
