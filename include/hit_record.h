#ifndef CSE3PSD_ASSIGNMENT3_HIT_RECORD_H
#define CSE3PSD_ASSIGNMENT3_HIT_RECORD_H
#include "vec3.h"
#include "material.h"
#include "helper_functions.h"
class HitRecord
{
  public:
  HitRecord(){};
  HitRecord(Point3 inHitPoint, Vec3 inSurfaceNormal, double inDistanceAlongRay, bool inFrontFace):hitPoint_{inHitPoint},surfaceNormal_{inSurfaceNormal},distanceAlongRay_{inDistanceAlongRay},frontFace_{inFrontFace}{};
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
