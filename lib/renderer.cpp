#include "../include/renderer.h"
#include "../include/colour.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <filesystem>
#include "../include/sphere.h"
#include "../include/scene.h"
#include "../include/pure_diffuse.h"
#include "../include/reflective.h"
#include "../include/plane.h"
std::string Renderer::FileHeader(int inImageWidth, int inImageHeight)
{
  std::stringstream string_stream;
  string_stream <<"P3\n"<<inImageWidth<<' '<<inImageHeight<<"\n255\n";
  return string_stream.str();
}
int Renderer::RenderImage()
{

  auto p = std::make_shared<Plane>(
    Point3(0.0, -0.5, -1.0),   
    Vec3(0, 1, 0),             
    Colour3(0.7, 0.7, 0.7),    
    REFLECTIVE
);
  auto s = std::make_shared<Sphere>(Point3(-1.25,0.0,-2.0),.5, Colour3(0.7,0.2,0.1),PURE_DIFFUSE);
  auto s2 = std::make_shared<Sphere>(Point3(1.25,0.0,-2.0),.5,Colour3(0.2,0.1,0.7),PURE_DIFFUSE);
  auto s3 = std::make_shared<Sphere>(Point3(0,0.0,-2.0),.5,Colour3(0.1,0.7,0.2),PURE_DIFFUSE);
  
  Scene scene;
  scene.Add(p);
  // scene.Add(s);
  // scene.Add(s2);
  scene.Add(s3);
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
      Colour3 pixel_colour(0.0,0.0,0.0);
      for(int sample =0; sample<this->sample_rate; ++sample)
      {
        double u = double(j)/(image_parameters->ImageWidth()-1);
        double v = double(i)/(image_parameters->ImageHeight()-1);
        Vec3 ray_direction = (camera_.LowerLeftCorner()+camera_.Horizontal()*u+camera_.Vertical()*v-camera_.Origin());
        
        Ray ray(camera_.Origin(), ray_direction.UnitVector());
        
        pixel_colour += RayColour(ray,this->maximum_recursion_depth, scene);
      }
      pixel_colour /= (double)this->sample_rate;
      WriteColour(outfile, pixel_colour);
    }
  }
  std::string path = std::filesystem::absolute(image_parameters->OutputFileName()).string();
  std::cout << " RAYTRACING COMPLETE \n File available at " << path << '\n';
  return 0;
}
