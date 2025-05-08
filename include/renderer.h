#ifndef CSE3PSD_ASSIGNMENT3_RENDERER
#define CSE3PSD_ASSIGNMENT3_RENDERER
#include <fstream>
#include "renderer_parameters.h"
#include "camera.h"
#include "scene.h"
class Renderer
{
  public: 
  private:
  RendererParameters rendererParameters_ {};
  std::ofstream outFile_;
  Camera camera_;
  Scene scene_;

};
#endif
