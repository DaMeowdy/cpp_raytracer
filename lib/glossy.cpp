#include "../include/glossy.h"
Vec3 Glossy::ReflectLight(HitRecord& rec, Ray r) const 
{
  // c++ has lambda functions. It is officially my favourite programming language
  auto reflect_=[](const Vec3& direction, const Vec3& normal)
  {
    return direction- 2* direction.Dot(normal)*normal;
  };
  Vec3 reflected = reflect_(r.Direction().UnitVector(),rec.normal);

  Vec3 fuzz = (1.0-this->gloss_factor_) * Vec3::RandomInUnitSphere();
  Vec3 scattered_direction = reflected + fuzz;
  return scattered_direction;
}
