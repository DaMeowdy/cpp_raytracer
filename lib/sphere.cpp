#include "../include/sphere.h"
// Colour3 Sphere::RayColour(const Ray& ray)
// {
//     auto t = HitSphere(Point3(0,0,-1), 0.5,ray);
//     if (t > 0.0) {
//         Vec3 N = ray.PointAlongRay(t) - Vec3(0,0,-1);
//         Vec3 o = N.UnitVector();
//         return 0.5*Colour3(o.X()+1,o.Y()+1, o.Z()+1);
//     }

//     Vec3 unit_direction = ray.Direction().UnitVector();
//     auto a = 0.5*(unit_direction.Y() + 1.0);
//     return ((1.0-a)*Colour3(1.0, 1.0, 1.0)) + (a * Colour3(0.5, 0.7, 1.0));
// }
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
  double value = discriminant_less_than_zero?-1.0:(-b - std::sqrt(discriminant) ) / (2.0*a);


  HitRecord record;
  
  
}
