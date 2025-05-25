#ifndef CSE3PSD_ASSIGNMENT_3_RAYTRACER_GLOSSY_H
#define CSE3PSD_ASSIGNMENT_3_RAYTRACER_GLOSSY_H
#include "material.h"
#include <memory>
class Glossy: public Material
{
  public:
  Glossy(double inGlossFactor):gloss_factor_(inGlossFactor){}
  Vec3 ReflectLight(HitRecord& rec, Ray r = Ray()) const override;
  private:
  double gloss_factor_{0.0};
};

static const std::shared_ptr<Glossy> LIGHT_GLOSSY = std::make_shared<Glossy>(0.75);
static const std::shared_ptr<Glossy> MEDIUM_GLOSSY = std::make_shared<Glossy>(0.5);
static const std::shared_ptr<Glossy> HEAVY_GLOSSY = std::make_shared<Glossy>(0.25);

#endif
