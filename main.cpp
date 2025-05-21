#include "include/renderer.h"
int main()
{
  // read args from command line

  // calculate aspect ratio
  double aspect_ratio = 1.0/1.0;
  Renderer renderer_("raytraced_image_21985164.ppm",1080 ,1080 ,aspect_ratio);
  renderer_.Configure(50,100,true);
  int rendering_successful = renderer_.RenderImage();
  if(rendering_successful == 1)
  {
    return 1;\
  }
  return 0; 
}
