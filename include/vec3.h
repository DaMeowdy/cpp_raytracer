#ifndef CSE3PSD_ASSIGNMENT_3_RAYTRACER_VEC3_H
#define CSE3PSD_ASSIGNMENT_3_RAYTRACER_VEC3_H
class Vec3 
{
  public:
  Vec3(double inX, double inY, double inZ):x_{inX},y_{inY},z_{inZ}{}
  Vec3 operator*(double scaler) const;
  private:
  double x_{0.0};
  double y_{0.0};
  double z_{0.0};
};
using Point3 = Vec3;
using Colour3 = Vec3;
#endif
