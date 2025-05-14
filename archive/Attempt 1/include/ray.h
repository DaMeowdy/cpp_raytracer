

#ifndef CSE3PSD_ASSIGNMENT3_RAY
#define CSE3PSD_ASSIGNMENT3_RAY

#include "vec3.h"

class Ray
{
  public: 
  Ray(const Point3& inOrigin, const Vec3& inDirection):origin_{inOrigin},direction_{inDirection} {}; 
  Point3 Origin() const {return origin_;}
  Vec3 Direction() const {return direction_;}
  Vec3 PointAlongRay(double distance) const; 
  
  private: 
  Point3 origin_;
  Vec3 direction_;
};
#endif
