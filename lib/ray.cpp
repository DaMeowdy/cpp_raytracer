#include "../include/ray.h"
Vec3 Ray::PointAlongRay(double distance) const
{
  Vec3 _pointAlongRay = Origin() + (Direction()*distance);
  return _pointAlongRay;
}
