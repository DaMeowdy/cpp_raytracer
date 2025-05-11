#include "../include/renderer_parameters.h"
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
