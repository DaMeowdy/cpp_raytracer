#ifndef CSE3PSD_ASSIGNMENT3_HIT_RECORD_H
#define CSE3PSD_ASSIGNMENT3_HIT_RECORD_H
#include "vec3.h"
#include "material.h"
#include "helper_functions.h"
class HitRecord
{
  public:
  Point3 HitPoint() const {return this->hitPoint_;}
  Vec3 SurfaceNormal() const{ return this->surfaceNormal_;}
  double DistanceAlongRay() const {return this->distanceAlongRay_;}
  bool FrontFace() const {return this->frontFace_;}
  private: 
  Point3 hitPoint_;
  Vec3 surfaceNormal_;
  // Material surfaceMaterial_;
  double distanceAlongRay_ {INFINITY_};
  bool frontFace_ {true};
};

#endif
