#ifndef CSE3PSD_ASSIGNMENT_3_RAYTRACER_CAMERA_H
#define CSE3PSD_ASSIGNMENT_3_RAYTRACER_CAMERA_H
#include "vec3.h"
class Camera
{
  public:
  Camera(double inAspectRatio);
  double ViewportWidth() const;
  double ViewportHeight() const;
  double AspectRatio() const;
  double FocalLength() const;
  Point3 Origin() const;
  Vec3 Horizontal() const;
  Vec3 Vertical() const;
  Vec3 LowerLeftCorner() const;
  private:
  double viewport_width_{0.0};
  double viewport_height_{0.0};
  double aspect_ratio_{0.0};
  double focal_length_{0.0};
  Point3 origin_{0.0,0.0,0.0};
  Vec3 horizontal_{0.0,0.0,0.0};
  Vec3 vertical_{0.0,0.0,0.0};
  Vec3 lower_left_corner_{0.0,0.0,0.0};
};
#endif
