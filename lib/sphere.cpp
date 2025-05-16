#include "../include/sphere.h"
bool Sphere::Hit(const Ray& ray, Interval ray_t,HitRecord& rec) const
{
  Vec3 oc = ray.Origin() - this->center_;
  auto a = ray.Direction().Length_Squared();
  auto half_b = oc.Dot(ray.Direction());
  auto c = oc.Length_Squared()- this->radius_*this->radius_;
  auto discriminant = half_b*half_b -a*c;
  if(discriminant<0) 
  {
    return false;
  }
  auto sqrtd = std::sqrt(discriminant);
  auto root = (-half_b - sqrtd)/a;
  if (!ray_t.Surrounds(root))
  {
    return false;
  }
  rec.t = root;
  rec.p = ray.At(rec.t);
  rec.normal = (rec.p - this->center_)/this->radius_;
  rec.attenuation = this->colour_;
  Vec3 direction = this->material_->ReflectLight(rec, ray);
  rec.scattered = Ray(rec.p, direction);
  return true;
}
Point3 Sphere::Center() const
{
  return this->center_;
}
double Sphere::Radius() const
{
  return this->radius_;
}
