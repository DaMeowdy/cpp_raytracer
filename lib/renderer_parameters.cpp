#include "../include/renderer_parameters.h"

RendererParameters::RendererParameters()
{
  this->imageWidth_=512;
  this->imageHeight_=512;
  this->sampleRate_=10;
  this->maximumRecursionDepth_=25;
  this->backgroundColour_ = Colour3(0.0,0.0,0.0);
  this->outputFileName_="raytraced_image_21985164.ppm";
}
int RendererParameters::ImageHeight()
{
  return this->imageHeight_;
}
int RendererParameters::ImageWidth()
{
  return this->imageWidth_;
}
int RendererParameters::SampleRate()
{
  return this->sampleRate_;
}
int RendererParameters::MaximumRecursionDepth()
{
  return this->maximumRecursionDepth_;
}
std::string RendererParameters::OutputFileName()
{
  return this->outputFileName_;
}
