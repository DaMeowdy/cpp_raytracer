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
  void Configure(int inDepth,int inSampleRate,bool inAntiAliasing);
  private:
  Image image_;
  Camera camera_;
  int maximum_recursion_depth_ = 0;
  int sample_rate_ = 0;
  bool anti_aliasing_on_ = false;
  bool isConfigured_ = false;
};
#endif

