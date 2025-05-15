#ifndef CSE3PSD_ASSIGNMENT_3_RAYTRACER_RAY_H
#define CSE3PSD_ASSIGNMENT_3_RAYTRACER_RAY_H
#include "vec3.h"


class Ray
{
  public:
  Ray(){};
  Ray(const Point3& inOrigin, const Vec3& inDirection):origin_(inOrigin),direction_(inDirection){}
  Point3 Origin() const;
  Vec3 Direction() const;
  Point3 At(double t) const;
  private:
  Point3 origin_;
  Vec3 direction_;
};
#endif
