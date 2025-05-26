#include "../include/renderer.h"
std::string Renderer::FileHeader(int inImageWidth, int inImageHeight)
{
  std::stringstream string_stream;
  string_stream <<"P3\n"<<inImageWidth<<' '<<inImageHeight<<"\n255\n";
  return string_stream.str();
}
int Renderer::RenderImage()
{
  if(!this->isConfigured_)
  {
    return 1;
  }
  auto p = std::make_shared<Plane>(
    Point3(0.0, -0.5, -1.0),   
    Vec3(0, 1, 0),             
    Colour3(0.7, 0.7, 0.7),    
    REFLECTIVE
);
  auto s = std::make_shared<Sphere>(Point3(-1.25,0.5,-3.0),.75, Colour3(0.7,0.2,0.1),HEAVY_GLOSSY);
  auto s2 = std::make_shared<Sphere>(Point3(1.25,0.0,-2.0),.25,Colour3(0.2,0.1,0.7),MEDIUM_GLOSSY);
  auto s3 = std::make_shared<Sphere>(Point3(0,0.0,-2.0),.5,Colour3(0.1,0.7,0.2),LIGHT_GLOSSY);
  
  Scene scene;
  scene.Add(p);
  scene.Add(s);
  scene.Add(s2);
  scene.Add(s3);
  scene.BuildBVH();
  Image* image_parameters = &this->image_;

  std::ofstream outfile(image_parameters->OutputFileName());
  if(!outfile.is_open())
  {
    std::cerr << "error opening file";
    return 1;
  }
  outfile << this->FileHeader(image_parameters->ImageWidth(),image_parameters->ImageHeight());
  ProgressBar bar(image_parameters->ImageHeight());
  for(int i = image_parameters->ImageHeight()-1;i>=0;--i)
  {
    bar.Update(image_parameters->ImageHeight() - i);
    for(int j =0;j<image_parameters->ImageWidth();++j)
    {
      double base_u = double(j)/(image_parameters->ImageWidth()-1);
      double base_v = double(i)/(image_parameters->ImageHeight()-1);
      Colour3 pixel_colour(0.0,0.0,0.0);
      if(this->anti_aliasing_on_)
      {
        for(int sample =0; sample<this->sample_rate_; ++sample)
        {
          double u = base_u + RandomDouble0to1()/image_parameters->ImageWidth();
          double v = base_v + RandomDouble0to1()/image_parameters->ImageHeight();

          Vec3 ray_direction = (camera_.LowerLeftCorner()+camera_.Horizontal()*u+camera_.Vertical()*v-camera_.Origin());
          
          Ray ray(camera_.Origin(), ray_direction.UnitVector());
          
          pixel_colour += RayColour(ray,this->maximum_recursion_depth_, scene);
        }
        pixel_colour /= (double)this->sample_rate_;
      }
      else
      {
        Vec3 ray_direction = (camera_.LowerLeftCorner()+camera_.Horizontal()*base_u+camera_.Vertical()*base_v-camera_.Origin());
        
        Ray ray(camera_.Origin(), ray_direction.UnitVector());
        
        pixel_colour = RayColour(ray,this->maximum_recursion_depth_, scene);
      }

      WriteColour(outfile, pixel_colour);
    }
  }
  bar.Done();
  std::string path = std::filesystem::absolute(image_parameters->OutputFileName()).string();
  std::cout << " RAYTRACING COMPLETE \n File available at " << path << '\n';
  return 0;
}
void Renderer::Configure(int inDepth,int inSampleRate,bool inAntiAliasing)
{
  this->anti_aliasing_on_ = inAntiAliasing;
  this->maximum_recursion_depth_ = inDepth;
  this->sample_rate_ = inSampleRate;
  this->isConfigured_ = true;
}
