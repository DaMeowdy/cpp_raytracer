#include <string>
#ifndef CSE3PSD_ASSIGNMENT_3_RAYTRACER_APP_CONFIG_H
#define CSE3PSD_ASSIGNMENT_3_RAYTRACER_APP_CONFIG_H
struct AppConfig
{
    int image_height_ = 1080;
  int image_width_ = 1080;
  std::string image_output_ ="21985164_RAY_TRACED_IMAGE.ppm";
  int renderer_max_depth_ = 150;
  int renderer_pixel_samples_ =100;
  bool renderer_anti_aliasing_ = true;
};

#endif
