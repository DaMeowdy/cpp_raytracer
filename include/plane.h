#ifndef CSE3PSD_ASSIGNMENT_3_RAYTRACER_PLANE_H
#define CSE3PSD_ASSIGNMENT_3_RAYTRACER_PLANE_H
#include "object.h"
#include <memory>
class Plane: public Object 
{
  public:
  Plane(Point3 inPoint, Vec3 inPlaneNormal, Colour3 inColour, std::shared_ptr<Material> inMaterial):point_(inPoint),plane_normal_(inPlaneNormal),colour_(inColour),material_(inMaterial){}
  bool Hit(const Ray& ray, Interval ray_t,HitRecord& rec) const override;
  Point3 Point() const;
  Vec3 PlaneNormal() const;
  Colour3 Colour() const;
  std::shared_ptr<Material> GetMaterial() const;

  private:
  Point3 point_;
  Vec3 plane_normal_;
  Colour3 colour_;
  std::shared_ptr<Material> material_;
};
#endif
