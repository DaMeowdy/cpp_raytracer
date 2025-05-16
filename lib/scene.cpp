#include "../include/scene.h"
void Scene::Add(std::shared_ptr<Object> object)
{
  this->objects_.push_back(object);
}
void Scene::Clear()
{
  this->objects_.clear();
}
Scene::Scene(std::shared_ptr<Object> object)
{
  this->Add(object);
}
bool Scene::Hit(const Ray& ray, Interval ray_t, HitRecord& rec) const
{
  bool hit_anything = false;
  double closest_so_far = ray_t.Max;

  for(const auto& object: objects_)
  {
    if(object->Hit(ray, Interval(ray_t.Min, closest_so_far), rec))
    {
      hit_anything=true;
      closest_so_far=rec.t;
    }
  }
  return hit_anything;
}
