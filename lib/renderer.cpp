#include "../include/renderer.h"

Renderer::Renderer()
{
  this->Setup();
}
void Renderer::Setup()
{
  this->camera_ = Camera();
  this->rendererParameters_ = RendererParameters();
  // this->scene_ = nullptr;
}
int Renderer::Render()
{
  int image_width = this->rendererParameters_.ImageWidth();
  int image_height = this->rendererParameters_.ImageHeight();
  std::string out_file_name = this->rendererParameters_.OutputFileName();
  std::ofstream out_file(out_file_name);

  if(!out_file.is_open())
  {
    std::cerr << "Error : unable to open file :C" << std::endl;
    return 1;
  }

  out_file << "P3\n" << image_width << " " << image_height << "\n255\n";
  for(int i = 0; i<image_height; ++i)
  {
    for(int j = 0; j<image_width; ++j)
    {
      Ray ray = this->camera_.GetRay(j, i);
      Colour3 pixel_colour = this->RayColor(ray);
      out_file << pixel_colour.R() << ' ' <<pixel_colour.G() << ' ' << pixel_colour.B()<<'\n';

    }
    this->progressBar_.UpdateProgressBar(i,image_height);
  }
  out_file.close();
  return 0;

}
Colour3 Renderer::RayColor(const Ray& ray)
{
  Vec3 unit_direction = ray.Direction().UnitVector();
  double lerp_factor = 0.5 * (unit_direction.Y() + 1.0);
  Colour3 white = Colour3(1.0, 1.0, 1.0);
  Colour3 blue = Colour3(0.5, 0.7, 1.0);
  return ((1.0 - lerp_factor) * white) + (lerp_factor * blue);
}
