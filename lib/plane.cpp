#include "../include/plane.h" 

bool Plane::Hit(const Ray& ray, Interval ray_t,HitRecord& rec) const
{
double denom = this->PlaneNormal().Dot(ray.Direction());

    if (fabs(denom) < 1e-8) {
        return false; // Ray is parallel to the plane
    }

    double t = (point_ - ray.Origin()).Dot(PlaneNormal()) / denom;

    if (!ray_t.Contains(t)) {
        return false;
    }

    rec.t = t;
    rec.p = ray.At(t);
    rec.SetFaceNormal(ray, this->plane_normal_);
    rec.attenuation = this->colour_;
    rec.direction = this->material_->ReflectLight(rec,ray);
    
    if(rec.direction.NearZero())
    {
      rec.direction = rec.direction = rec.normal;
    }
    rec.scattered = Ray(rec.p, rec.direction);
    return true;
}
Point3 Plane::Point() const
{
  return this->point_;
}
Vec3 Plane::PlaneNormal() const
{
  return this->plane_normal_;
}
Colour3 Plane::Colour() const
{
  return this->colour_;
}
std::shared_ptr<Material> Plane::GetMaterial() const
{
  return this->material_;
}
