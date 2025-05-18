#include "../include/pure_diffuse.h"
#include <memory>

Vec3 PureDiffuse::ReflectLight(HitRecord& rec, Ray r) const 
{
  Vec3 ray_direction = rec.normal + Vec3::RandomInUnitSphere();
  return ray_direction.UnitVector();
}
