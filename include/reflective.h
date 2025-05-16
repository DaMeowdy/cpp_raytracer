#ifndef CSE3PSD_ASSIGNMENT_3_RAYTRACER_REFLECTIVE_H
#define CSE3PSD_ASSIGNMENT_3_RAYTRACER_REFLECTIVE_H
#include "material.h"
#include <memory>
class Reflective: public Material
{
  public:
  Vec3 ReflectLight(HitRecord& rec, Ray r = Ray()) const override;
};
static const std::shared_ptr<Reflective> REFLECTIVE = std::make_shared<Reflective>();
#endif
