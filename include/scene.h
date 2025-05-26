#ifndef CSE3PSD_ASSIGNMENT_3_RAYTRACER_SCENE_H
#define CSE3PSD_ASSIGNMENT_3_RAYTRACER_SCENE_H
#include "object.h"
#include "bvh_node.h"
#include <memory>

class Scene: public Object 
{
  public:
  Scene(){}
  Scene(std::shared_ptr<Object> object);
  bool Hit(const Ray& ray, Interval ray_t, HitRecord& rec) const override;
  bool BoundingBox(AABB& output_box) const override;
  void BuildBVH();
  void Clear();
  void Add(std::shared_ptr<Object> object);
  private:
  std::shared_ptr<BVHNode> bvh_root_;
  std::vector<std::shared_ptr<Object>> objects_;
};
#endif
