#ifndef CSE3PSD_ASSIGNMENT_3_RAYTRACER_IMAGE_H
#define CSE3PSD_ASSIGNMENT_3_RAYTRACER_IMAGE_H
#include <string>
class Image
{
  public:
  Image(){}
  Image(std::string inFileName, int inImageWidth, int inImageHeight, double inAspectRatio):output_filename_{inFileName},image_width_{inImageWidth},aspect_ratio_{inAspectRatio},image_height_{inImageHeight}{}
  std::string OutputFileName() const;
  int ImageHeight() const;
  int ImageWidth() const;
  double AspectRatio() const;
  private:
  std::string output_filename_{""};
  double aspect_ratio_{1.0/1.0};
  int image_height_{0};
  int image_width_{0};
};
#endif
