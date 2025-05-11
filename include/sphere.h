#ifndef CSE3PSD_ASSIGNMENT3_SPHERE_H
#define CSE3PSD_ASSIGNMENT3_SPHERE_H
#include "object.h"

class Sphere: public Object
{
  public:
  Sphere(double inRadius, Point3 inCenter):radius_{inRadius},center_{inCenter}{};
  std::optional<HitRecord> RayHit(const Ray& ray, Interval rayInterval) const override;
  Colour3 RayColour(const Ray& ray) override;
  double Radius() const;
  Point3 Center() const;  
  private:
  double radius_ {};
  Point3 center_ {};

};

#endif
