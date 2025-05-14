#ifndef CSE3PSD_ASSIGNMENT3_CAMERA
#define CSE3PSD_ASSIGNMENT3_CAMERA
#include "vec3.h"
#include "ray.h"

class Camera
{
  public: 
  Camera(const Point3& inCameraPosition = Vec3(0,0,0),const Point3& inImagePlaneCentre = Vec3(0,0,0), double inImageHeight = 512, double inAspectRatio =1);
  Ray GetRay(double inX, double inY);
  private:
  Point3 cameraCentre_ {0.0,0.0,0.0};
  Point3 pixel00_ {0.0, 0.0, 0.0};
  Vec3 horizontalStep_ {1.0, 0.0, 0.0};
  Vec3 verticalStep_ {0.0, 1.0, 0.0};
};
#endif
