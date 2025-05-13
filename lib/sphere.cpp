#include "../include/sphere.h"
Colour3 Sphere::RayColour(const Ray& ray)
{
    Vec3 unit_direction = ray.Direction().UnitVector();
    auto a = 0.5*(unit_direction.Y() + 1.0);
    return ((1.0-a)*Colour3(1.0, 1.0, 1.0)) + (a * Colour3(0.5, 0.7, 1.0));
}
std::optional<HitRecord> Sphere::RayHit(const Ray& ray, Interval rayInterval) const
{
  Vec3 origin = ray.Origin();
  Vec3 direction = ray.Direction();
  Point3 center = this->Center();
  double radius = this->Radius();
  Vec3 oc = this->Center() - origin;
  double a = direction.Dot(direction);
  double b = -2.0 * direction.Dot(oc);
  double c = oc.Dot(oc) - radius*radius;
  double discriminant = b*b - 4*a*c;
  bool discriminant_less_than_zero = discriminant < 0;
  double root = (-b - std::sqrt(discriminant) ) / (2.0*a);
  double value = discriminant_less_than_zero?-1.0:root;

  HitRecord record;
  
  return record;
  
}

double Sphere::Radius() const
{
  return this->radius_;
}
Point3 Sphere::Center() const
{
  return this->center_;
} 
