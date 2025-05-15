#include "../include/renderer.h"
#include "../include/colour.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <filesystem>
#include "../include/sphere.h"

std::string Renderer::FileHeader(int inImageWidth, int inImageHeight)
{
  std::stringstream string_stream;
  string_stream <<"P3\n"<<inImageWidth<<' '<<inImageHeight<<"\n255\n";
  return string_stream.str();
}
int Renderer::RenderImage()
{
  Sphere s(Point3(0.0,0.0,-1.0),.5);
  Image* image_parameters = &this->image_;

  std::ofstream outfile(image_parameters->OutputFileName());
  if(!outfile.is_open())
  {
    std::cerr << "error opening file";
    return 1;
  }
  outfile << this->FileHeader(image_parameters->ImageWidth(),image_parameters->ImageHeight());
  for(int i = image_parameters->ImageHeight()-1;i>=0;--i)
  {
    std::cerr << "remaining lines : " << i << '\n';
    for(int j =0;j<image_parameters->ImageWidth();++j)
    {
      double u = double(j)/(image_parameters->ImageWidth()-1);
      double v = double(i)/(image_parameters->ImageHeight()-1);
      Ray ray(camera_.Origin(), camera_.LowerLeftCorner()+camera_.Horizontal()*u+camera_.Vertical()*v-camera_.Origin());

      auto t = s.HitSphere(ray);
      Colour3 pixel_colour;
      if(t>0.0)
      {
        Point3 p(ray.At(t));
        Vec3 temp = p-s.Center();
        Vec3 un = temp.UnitVector();
        pixel_colour = 0.5*Colour3(un.X()+1,un.Y()+1,un.Z()+1);
      }
      else
      {
        pixel_colour = GetColour(ray);
      }
      WriteColour(outfile, pixel_colour);
    }
  }
  std::string path = std::filesystem::absolute(image_parameters->OutputFileName()).string();
  std::cout << " RAYTRACING COMPLETE \n File available at " << path << '\n';
  return 0;
}
