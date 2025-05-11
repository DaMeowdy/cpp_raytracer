#include <string>
#include "colour3.h"
#ifndef CSE3PSD_ASSIGNMENT3_RENDERER_PARAMETERS
#define CSE3PSD_ASSIGNMENT3_RENDERER_PARAMETERS
class RendererParameters 
{
  public:
  static RendererParameters defaultParameters();
  int ImageWidth();
  int ImageHeight();
  int SampleRate();
  int MaximumRecursionDepth();
  Colour3 BackgroundColour();
  std::string OutputFileName();
  private:
  int imageWidth_ {512};
  int imageHeight_ {512};
  int sampleRate_ {10};
  int maximumRecursionDepth_ {25};
  Colour3 backgroundColour_ {0.0,0.0,0.0};
  std::string outputFileName_ {"raytraced_image_21985164.ppm"};

};

#endif
