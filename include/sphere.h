#ifndef CSE3PSD_ASSIGNMENT_3_RAYTRACER_SPHERE_H
#define CSE3PSD_ASSIGNMENT_3_RAYTRACER_SPHERE_H
#include "vec3.h"
#include "ray.h"
#include "hit_record.h"
#include "object.h"
#include <memory>
class Sphere: public Object
{
  public:
  Sphere(Point3 inCenter, double inRadius, Colour3 inColour,std::shared_ptr<Material> inMaterial):center_{inCenter},radius_{inRadius},colour_{inColour},material_{inMaterial}{}
  bool Hit(const Ray& ray, Interval ray_t,HitRecord& rec) const override;
  Point3 Center() const;
  double Radius() const;
  private:
  Point3 center_ {0.0,0.0,0.0};
  double radius_ {0};
  Colour3 colour_ {0.0,0.0,0.0};
  std::shared_ptr<Material> material_;
};
#endif
