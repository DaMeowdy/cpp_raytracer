#include "../include/sphere.h"
double Sphere::HitSphere(const Ray& ray)
{
  Vec3 oc = ray.Origin() - this->center_;
  auto a = ray.Direction().Length_Squared();
  auto half_b = oc.Dot(ray.Direction());
  auto c = oc.Length_Squared()- this->radius_*this->radius_;
  auto discriminant = half_b*half_b -a*c;
  if(discriminant<0)
  {
    return -1.0;
  }
  else
  {
    return (-half_b-std::sqrt(discriminant))/a;
  }
}
Point3 Sphere::Center() const
{
  return this->center_;
}
double Sphere::Radius() const
{
  return this->radius_;
}
