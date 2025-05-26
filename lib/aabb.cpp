#include "../include/aabb.h"
AABB::AABB(const Point3& a, const Point3& b)
{
  this->x_ = Interval(fmin(a.X(), b.X()), fmax(a.X(), b.X()));
  this->y_ = Interval(fmin(a.Y(), b.Y()), fmax(a.Y(), b.Y()));
  this->z_ = Interval(fmin(a.Z(), b.Z()), fmax(a.Z(), b.Z()));
}
Interval AABB::X() const
{
  return this->x_;
}
Interval AABB::Y() const
{
  return this->y_;
}
Interval AABB::Z() const
{
  return this->z_;
}
bool AABB::Hit(const Ray& ray, Interval ray_t) const
{
  for (int a = 0; a < 3; ++a) {
    auto invD = 1.0 / ray.Direction()[a];
    auto orig = ray.Origin()[a];

    auto t0 = (Min()[a] - orig) * invD;
    auto t1 = (Max()[a] - orig) * invD;

    if (invD < 0.0) std::swap(t0, t1);

    ray_t.Min = fmax(t0, ray_t.Min);
    ray_t.Max = fmin(t1, ray_t.Max);

    if (ray_t.Max <= ray_t.Min)
        return false;
  }
  return true;
}
Point3 AABB::Min() const
{
  return Point3(x_.Min, y_.Min, z_.Min);
}
Point3 AABB::Max() const
{
  return Point3(x_.Max, y_.Max, z_.Max);
}
AABB AABB::SurroundingBox(const AABB& box_a, const AABB& box_b)
{
  Interval x = Interval::Surrounding(box_a.X(), box_b.X());
  Interval y = Interval::Surrounding(box_a.Y(), box_b.Y());
  Interval z = Interval::Surrounding(box_a.Z(), box_b.Z());
  return AABB(x,y,z);

}
