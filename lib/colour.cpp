#include "../include/colour.h"

double LinearValueToGamma(double LinearComponent)
{
  return std::sqrt(LinearComponent) ;
}

void WriteColour(std::ostream &out, Colour3 inPixelColour)
{
  Interval intensity(0.000,0.999);
  double RGBScaler = 256;
  double gammaR = LinearValueToGamma(inPixelColour.X());
  double gammaG = LinearValueToGamma(inPixelColour.Y());
  double gammaB = LinearValueToGamma(inPixelColour.Z());
  int R = static_cast<int>(RGBScaler*intensity.ClampValue(gammaR));
  int G = static_cast<int>(RGBScaler*intensity.ClampValue(gammaG));
  int B = static_cast<int>(RGBScaler*intensity.ClampValue(gammaB));
  out << R << ' ' << G << ' ' << B << '\n';
}
Colour3 RayColour(const Ray& ray, int depth, const Scene& scene)
{
  HitRecord rec;
  if (depth == 0)
  {
    return Colour3(0,0,0);
  }

  if(!scene.Hit(ray, Interval(0.001, INFINITY_),rec))      
  {    
    Vec3 unit_direction = ray.Direction().UnitVector();
    auto t = 0.5*(unit_direction.Y()+1.0);
    return (1.0-t)*Colour3(1.0,1.0,1.0)+t*Colour3(0.5,0.7,1.0);
  }
  if (rec.scattered.Direction().Length_Squared() < 1e-8) 
  {
    return Colour3(0,0,0);
  }
  return rec.attenuation*RayColour(rec.scattered,depth-1,scene)*0.5;
}
