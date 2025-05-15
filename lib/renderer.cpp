#include "../include/renderer.h"
#include "../include/colour.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <filesystem>


std::string Renderer::FileHeader(int inImageWidth, int inImageHeight)
{
  std::stringstream string_stream;
  string_stream <<"P3\n"<<inImageWidth<<' '<<inImageHeight<<"\n255\n";
  return string_stream.str();
}
int Renderer::RenderImage()
{
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
      Vec3 vec(camera_.LowerLeftCorner()+camera_.Horizontal()*u+camera_.Vertical()*v-camera_.Origin());

      Colour3 pixel_colour = GetColour(vec);
      WriteColour(outfile, pixel_colour);
    }
  }
  std::string path = std::filesystem::absolute(image_parameters->OutputFileName()).string();
  std::cout << " RAYTRACING COMPLETE \n File available at " << path << '\n';
  return 0;
}
