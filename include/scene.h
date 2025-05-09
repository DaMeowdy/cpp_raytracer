#ifndef CSE3PSD_ASSIGNMENT3_SCENE_H
#define CSE3PSD_ASSIGNMENT3_SCENE_H
#include "object.h"

class Scene: public Object
{
  Scene(Object* object);
  void Add(Object* object);
  void Clear();
  std::optional<HitRecord> RayHit(const Ray& ray, Interval rayInterval) const override;
  private:
  std::vector<Object*> objects_ {};
};

#endif
