#include "../include/scene.h"
Scene::Scene(Object* object)
{
  this->Add(object);
}
void Scene::Add(Object* object)
{
  this->objects_.push_back(object);
}
void Scene::Clear()
{
  this->objects_.clear();
}
std::optional<HitRecord> Scene::RayHit(const Ray& ray, Interval rayInterval) const
{
  HitRecord temporary_hit_record;
  bool hit_anything = false;
  double closest_so_far = rayInterval.Max();
  for(const auto& object: this->objects_)
  {
    if(auto temp_hit = object->RayHit(ray, Interval(rayInterval.Min(), closest_so_far)))
    {
      hit_anything = true;
      closest_so_far = temp_hit->DistanceAlongRay();
      temporary_hit_record = *temp_hit;
    }
  }
  return hit_anything?std::optional<HitRecord>{temporary_hit_record}:std::nullopt;
}
