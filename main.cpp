#include "include/renderer.h"
int main()
{
  double aspect_ratio = 1.0/1.0;
  Renderer renderer_("first_image.ppm",512 ,512 ,aspect_ratio);
  int rendering_successful = renderer_.RenderImage();
  if(rendering_successful == 1)
  {
    return 1;
  }
  return 0; 
}
