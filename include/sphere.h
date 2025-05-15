#ifndef CSE3PSD_ASSIGNMENT_3_RAYTRACER_SPHERE_H
#define CSE3PSD_ASSIGNMENT_3_RAYTRACER_SPHERE_H
#include "vec3.h"
#include "ray.h"
class Sphere
{
  public:
  Sphere(Point3 inCenter, double inRadius):center_{inCenter},radius_{inRadius}{}
  double HitSphere(const Ray& ray);
  Point3 Center() const;
  double Radius() const;
  private:
  Point3 center_ {0.0,0.0,0.0};
  double radius_ {0};
};
#endif
