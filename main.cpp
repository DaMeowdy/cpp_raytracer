#include "include/renderer.h"
int main(int argc, char* argv[])
{
  // read args from command line
  double height = 1080;
  double width = 1080;
  int sample_rate = 50;
  int depth = 20;
  bool anti_aliasing = true;
  // calculate aspect ratio
    if (argc > 1) {
    int h = std::atoi(argv[1]);
    if (h > 0) height = h;
  }
  if (argc > 2) {
    int w = std::atoi(argv[2]);
    if (w > 0) width = w;
  }
  if (argc > 3) {
    int aa = std::atoi(argv[3]);
    anti_aliasing = (aa != 0);
  }
  int pixel_count = static_cast<int>(height*width);
  int cat = 0;
  if(pixel_count < 1280*720){
    cat = 0;
  }else if(pixel_count < 1920*1080){
    cat = 1;
  }else if(pixel_count <3840 * 2160){
    cat = 2;
  }else {
    cat = 3;
  }
  switch (cat) {
    case 0:
      sample_rate = 32;
      depth = 15;  
      break;
    case 1:
      sample_rate = 48;
      depth = 20;
      break;
    case 2:
      sample_rate = 56;
      depth = 25;
      break;
    case 3:
      sample_rate = 64;
      depth = 32;
      break;
    default:
      sample_rate = 32;
      depth = 15;  
  }

  double aspect_ratio = width/height;
  Renderer renderer_("raytraced_image_21985164.ppm",width ,height ,aspect_ratio);
  renderer_.Configure(20,50,anti_aliasing);
  int rendering_successful = renderer_.RenderImage();
  if(rendering_successful == 1)
  {
    return 1;
  }
  return 0; 
}
