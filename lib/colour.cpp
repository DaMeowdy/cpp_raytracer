#include "../include/colour.h"

void WriteColour(std::ostream &out, Colour3 inPixelColour)
{
  double RGBScaler = 255.999;
  int R = static_cast<int>(RGBScaler*inPixelColour.X());
  int G = static_cast<int>(RGBScaler*inPixelColour.Y());
  int B = static_cast<int>(RGBScaler*inPixelColour.Z());
  out << R << ' ' << G << ' ' << B << '\n';
}
Colour3 RayColour(const Ray& ray, int depth, const Scene& scene)
{
  HitRecord rec;
  if(scene.Hit(ray, Interval(0, INFINITY_),rec))
  {
    
    return 0.5*(rec.normal+Colour3(1.0,1.0,1.0));
  }
  Vec3 unit_direction = ray.Direction().UnitVector();
  auto t = 0.5*(unit_direction.Y()+1.0);
  return (1.0-t)*Colour3(1.0,1.0,1.0)+t*Colour3(0.5,0.7,1.0);
}
