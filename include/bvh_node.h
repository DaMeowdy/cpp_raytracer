#ifndef CSE3PSD_ASSIGNMENT_3_BVH_NODE_H
#define CSE3PSD_ASSIGNMENT_3_BVH_NODE_H
#include "object.h"
#include "aabb.h"
#include <vector>
#include <memory>
#include <algorithm>
#include <cstdlib>
class BVHNode: public Object
{
  public:
  BVHNode() = default;
  BVHNode(std::vector<std::shared_ptr<Object>>& objects, size_t start, size_t end);
  bool Hit(const Ray& ray, Interval ray_t, HitRecord& rec) const override;
  bool BoundingBox(AABB& output_box) const override;
  static bool BoxCompare(const std::shared_ptr<Object> a, const std::shared_ptr<Object> b, int axis);

  private:
  std::shared_ptr<Object> left_;
  std::shared_ptr<Object> right_;
  AABB box_;

};
#endif
