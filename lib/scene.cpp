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
void Scene::BuildBVH()
{
  this->bvh_root_ = std::make_shared<BVHNode>(objects_, 0, objects_.size());
}
bool Scene::Hit(const Ray& ray, Interval ray_t, HitRecord& rec) const
{
  if (bvh_root_)
  {
    return bvh_root_->Hit(ray, ray_t, rec);
  }
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
bool Scene::BoundingBox(AABB& output_box) const {
  if (objects_.empty()) return false;

  AABB temp_box;
  bool first_box = true;

  for (const auto& object : objects_)
  {
    if (!object->BoundingBox(temp_box))
      return false;

    output_box = first_box ? temp_box : AABB::SurroundingBox(output_box, temp_box);
    first_box = false;
  }
  return true;
}
