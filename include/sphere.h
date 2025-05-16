#ifndef CSE3PSD_ASSIGNMENT_3_RAYTRACER_SPHERE_H
#define CSE3PSD_ASSIGNMENT_3_RAYTRACER_SPHERE_H
#include "vec3.h"
#include "ray.h"
#include "hit_record.h"
#include "object.h"
class Sphere: public Object
{
  public:
  Sphere(Point3 inCenter, double inRadius):center_{inCenter},radius_{inRadius}{}
  bool Hit(const Ray& ray, double t_min,double t_max,HitRecord& rec) const override;
  Point3 Center() const;
  double Radius() const;
  private:
  Point3 center_ {0.0,0.0,0.0};
  double radius_ {0};
};
#endif
