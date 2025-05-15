#include "../include/ray.h"

Point3 Ray::Origin() const 
{
  return this->origin_;
}
Vec3 Ray::Direction() const
{
  return this->direction_;
}
Point3 Ray::At(double t) const 
{
  Point3 ray_at = this->origin_+ t*direction_;
  return ray_at;
}
