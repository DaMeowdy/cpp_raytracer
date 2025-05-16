#include "../include/reflective.h"


Vec3 Reflective::ReflectLight(HitRecord& rec, Ray r) const
{
  Vec3 ray_direction = r.Direction();
  Vec3 vector_normal = rec.normal;
  return ray_direction- 2* ray_direction.Dot(vector_normal)*vector_normal;
}
