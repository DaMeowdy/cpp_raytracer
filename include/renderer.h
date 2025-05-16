#include <string>
#ifndef CSE3PSD_ASSIGNMENT_3_RAYTRACER_RENDERER_H
#define CSE3PSD_ASSIGNMENT_3_RAYTRACER_RENDERER_H
#include "image.h"
#include "camera.h"
class Renderer
{
  public:
  Renderer(std::string inFileName, int inImageWidth,int inImageHeight, double inAspectRatio):image_{Image(inFileName,inImageWidth,inImageHeight,inAspectRatio)},camera_(inAspectRatio){}
  std::string FileHeader(int inImageWidth, int inImageHeight);
  int RenderImage();
  private:
  Image image_;
  Camera camera_;
  int maximum_recursion_depth = 50;
};
#endif

