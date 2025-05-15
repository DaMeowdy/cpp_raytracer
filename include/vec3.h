#ifndef CSE3PSD_ASSIGNMENT_3_RAYTRACER_VEC3_H
#define CSE3PSD_ASSIGNMENT_3_RAYTRACER_VEC3_H
#include <ostream>
#include "helper_functions.h"
class Vec3 
{
  public:
  // constructors
  Vec3() = default;
  Vec3(double inX, double inY, double inZ):x_{inX},y_{inY},z_{inZ}{}
  // getters
  double X() const;
  double Y() const;
  double Z() const;
  // operator overrides/ definitions
  Vec3 operator-()const;
  Vec3 operator-(const Vec3 otherVector) const;
  Vec3 operator+(const Vec3 otherVector) const;
  Vec3 operator*(double scaler) const;
  Vec3 operator/(double scale) const;
  friend Vec3 operator*(double scale, const Vec3& otherVector);
  friend Vec3 operator/(double scale, const Vec3& otherVector);
  Vec3& operator+=(const Vec3& inVector);
  Vec3& operator*=(double scale);
  Vec3& operator/=(double scale);
  friend std::ostream& operator<<(std::ostream outputStream,const Vec3& vector);
  // helper functions
  double Dot(const Vec3& otherVector) const;
  Vec3 Cross(const Vec3 otherVector) const;
  double Length_Squared() const;  
  double Length() const;
  Vec3 UnitVector() const;
  bool NearZero(double epsilon = 1e-8) const;
  Vec3 ReflectionAboutNormalVector(const Vec3& normalVector)const;
  Vec3 RefractionAboutNormalVector(const Vec3& normalVector, double refractiveIndexRatio) const;
  static Vec3 Random0to1();
  static Vec3 RandomInRange(double minimum, double maximum);
  static Vec3 RandomInUnitSphere();
  static Vec3 RandomInUnitDisk();
  static Vec3 RandomUnitVector();
  static Vec3 RandomOnHemisphere(const Vec3& normalVector);
  private:
  double x_{0.0};
  double y_{0.0};
  double z_{0.0};
};
using Point3 = Vec3;
using Colour3 = Vec3;
#endif
