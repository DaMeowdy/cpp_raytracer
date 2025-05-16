#ifndef CSE3PSD_ASSIGNMENT_3_RAYTRACER_PURE_DIFFUSE_H
#define CSE3PSD_ASSIGNMENT_3_RAYTRACER_PURE_DIFFUSE_H
#include "material.h"
#include <memory>

class PureDiffuse: public Material
{
  public:
  Vec3 ReflectLight(HitRecord& rec, Ray r = Ray()) const override;
};
static const std::shared_ptr<PureDiffuse> PURE_DIFFUSE= std::make_shared<PureDiffuse>();
#endif
