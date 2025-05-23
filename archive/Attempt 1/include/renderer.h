#ifndef CSE3PSD_ASSIGNMENT3_RENDERER
#define CSE3PSD_ASSIGNMENT3_RENDERER
#include <fstream>
#include "renderer_parameters.h"
#include "camera.h"
#include "scene.h"
#include "progress_bar.h"
class Renderer
{
  public: 
  Renderer():scene_{Scene(nullptr)}{};
  int Render();
  void Setup();
  Colour3 RayColour(const Ray& ray);
  private:
  RendererParameters rendererParameters_ {};
  std::ofstream outFile_;
  Camera camera_;
  Scene scene_;
  ProgressBar progressBar_;

};
#endif
