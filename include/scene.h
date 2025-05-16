#ifndef CSE3PSD_ASSIGNMENT_3_RAYTRACER_SCENE_H
#define CSE3PSD_ASSIGNMENT_3_RAYTRACER_SCENE_H
#include "object.h"
#include <memory>

class Scene: public Object 
{
  public:
  bool Hit(const Ray& ray, Interval ray_t, HitRecord& rec) const override;
  Scene(){}
  Scene(std::shared_ptr<Object> object);
  void Clear();
  void Add(std::shared_ptr<Object> object);
  private:
  std::vector<std::shared_ptr<Object>> objects_;
};
#endif
