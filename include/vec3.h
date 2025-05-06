#ifndef CSE3PSD_ASSIGNMENT3_VEC3
#define CSE3PSD_ASSIGNMENT3_VEC3
#include <ostream>
#include "helper_functions.h"
class Vec3
{
  public: 
  Vec3() = default;
  Vec3(double inX, double inY, double inZ): x_{inX}, y_{inY},z_{inZ} {};
  // Woag getters for private variables 
  double X() const {return x_;}
  double Y() const {return y_;}
  double Z() const {return z_;}
  // Basic Arithmetic operators 
  Vec3 operator-()const;
  Vec3 operator-(const Vec3 otherVector) const;
  Vec3 operator+(const Vec3 otherVector) const;
  Vec3 operator*(double scale) const;
  Vec3 operator/(double scale) const;
  // We getting friendly in here 
  friend Vec3 operator*(double scale, Vec3& otherVector);
  friend Vec3 operator/(double scale, Vec3& otherVector);
  // Not so basic arithmetic operators 
  Vec3& operator+=(const Vec3& inVector);
  Vec3& operator*=(double scale);
  Vec3& operator/=(double scale);
  // Another operator definition/ override 
  friend std::ostream& operator<<(std::ostream outputStream,const Vec3& vector);
  // Will need to read the definitions to figure out what these methods are so I can leave a more insightful comment
  double Dot(const Vec3& otherVector) const;
  Vec3 Cross(const Vec3 otherVector) const;
  double Length_squared() const;  
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
  double x_ {0.0};
  double y_ {0.0};
  double z_ {0.0};

};

using Point3 = Vec3;

#endif
