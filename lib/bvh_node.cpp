#include "../include/bvh_node.h"


BVHNode::BVHNode(std::vector<std::shared_ptr<Object>>& objects, size_t start, size_t end) {
  size_t object_span = end - start;

  int axis = rand() % 3; // randomly choose axis 0=x,1=y,2=z
  auto comparator = [axis](const std::shared_ptr<Object> a, const std::shared_ptr<Object> b) {
      return BoxCompare(a, b, axis);
  };

  if (object_span == 1) {
      left_ = right_ = objects[start];
  } else if (object_span == 2) {
      if (comparator(objects[start], objects[start + 1])) {
          left_ = objects[start];
          right_ = objects[start + 1];
      } else {
          left_ = objects[start + 1];
          right_ = objects[start];
      }
  } else {
      std::sort(objects.begin() + start, objects.begin() + end, comparator);
      size_t mid = start + object_span / 2;
      left_ = std::make_shared<BVHNode>(objects, start, mid);
      right_ = std::make_shared<BVHNode>(objects, mid, end);
  }

  AABB box_left, box_right;

  if (!left_->BoundingBox(box_left) || !right_->BoundingBox(box_right))
      std::cerr << "No bounding box in BVHNode constructor.\n";

  box_ = AABB::SurroundingBox(box_left, box_right);
}

bool BVHNode::Hit(const Ray& ray, Interval ray_t, HitRecord& rec) const {
    if (!box_.Hit(ray, ray_t)) return false;

    bool hit_left = left_->Hit(ray, ray_t, rec);
    bool hit_right = right_->Hit(ray, Interval(ray_t.Min, hit_left ? rec.t : ray_t.Max), rec);

    return hit_left || hit_right;
}

bool BVHNode::BoundingBox(AABB& output_box) const {
    output_box = box_;
    return true;
}

bool BVHNode::BoxCompare(const std::shared_ptr<Object> a, const std::shared_ptr<Object> b, int axis) {
    AABB box_a, box_b;

    if (!a->BoundingBox(box_a) || !b->BoundingBox(box_b)) {
        std::cerr << "No bounding box in BoxCompare.\n";
    }

    return box_a.Min()[axis] < box_b.Min()[axis];
}
