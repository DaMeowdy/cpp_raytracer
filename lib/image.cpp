#include "../include/image.h"
std::string Image::OutputFileName() const
{
  return this->output_filename_;
}
int Image::ImageHeight() const
{
  return this->image_height_;
}
int Image::ImageWidth() const
{
  return this->image_width_;
}
double Image::AspectRatio() const
{
  return this->aspect_ratio_;
}
